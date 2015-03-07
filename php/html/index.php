<?php
	require "server.php";
	ini_set('session.save_path', getcwd().'/session_tmp');
	session_start();
	ini_set('display_errors','On');
	date_default_timezone_set("America/Detroit");
	// Include the Smarty Templating Engine
	define('SMARTY_DIR', __DIR__ . '/Smarty-3.1.14/libs/');
	require_once(SMARTY_DIR . 'Smarty.class.php');
	$smarty = new Smarty();
	
	$smarty->setTemplateDir(__DIR__ . '/templates/templates/');
	$smarty->setCompileDir(__DIR__ . '/templates/templates_c/');
	$smarty->setConfigDir(__DIR__ . '/templates/configs/');
	$smarty->setCacheDir(__DIR__ . '/templates/cache/');

	// Notice how you can set variables here in the PHP that will get carried into the template files
	$smarty->assign('title', "EECS485");

	// Setup the Routing Framework
	require_once __DIR__ . '/vendor/autoload.php';
	$klein = new \Klein\Klein();

	//*******************************
/*	// load xml file to the database;
	$xml = simplexml_load_file("search.xml");
	$con = mysqli_connect("","group71","group71","group71pa2");
	for ($i =0; $i<200; $i++){
		$url =  $xml->photo[$i]["url"];
		$caption = $xml->photo[$i]["caption"];
//		print($caption);
//		echo "<br>";
		$datetaken = $xml->photo[$i]["datetaken"];
		$filename = $xml->photo[$i]["filename"];
		$sequencenum = $xml->photo[$i]["sequencenum"];
		$sql1= "insert into Photo values ('".$sequencenum."','/static/".$url."','jpg','".$datetaken."');";
		mysqli_query($con, $sql1);

//		$sql2= "insert into Contain values ('8','".$sequencenum."','".$caption."','".$sequencenum."');";
//		echo $sql2; echo "<br>";
		$sql2= "insert into Contain values ('8','$sequencenum','$caption','$sequencenum');";
		mysqli_query($con, $sql2);
	}
	
	mysqli_close($con);
*/
	//*********************************

	/* Define routes here */
	// *** function to check if the inactivity time has go over the limit;
	function check_if_expired(){
		if(isset($_SESSION['name'])){
			if ((time()-$_SESSION['last_activity'])>300){// expire time is 5 mins; 
				session_destroy();
				$url = "Location: http://eecs485-08.eecs.umich.edu:5671/rjyohh/pa6/login";
				header($url);
				exit;
			}
			else{
				$_SESSION['last_activity'] = time();
			}
		}
	}
	//*********************
	//**** new added search page******
	$klein->respond('GET', '/rjyohh/pa6/search', function ($request, $response, $service) use ($smarty) {
		$smarty->display('search_main.tpl');
	});
				
	$klein->respond('POST', '/rjyohh/pa6/search', function ($request, $response, $service) use ($smarty) {
		$con = mysqli_connect("","group71","group71","group71pa2");
		$query = $_POST['q'];
		$w = $_POST['w'];
		$myResults = queryIndex(6071, "localhost", $query, $w); //send a query to the server
//		var_dump($myResults);

		$hit_result = array();
		$hit_result2 = array();
		$hit_result3 = array();
		$hit_result4 = array();
		$size = min(sizeof($myResults), 10);
		for($i=0; $i<$size;$i++){
			//get the url;
			$sql_sel1 = "select pageUrl, pageTitle from PageUrl where pageID=".$myResults[$i]["id"].";";
			$result1 = mysqli_query($con, $sql_sel1);
			$row = mysqli_fetch_array($result1);
			$hit_result[] = array('id'=> $myResults[$i]["id"], 'url'=>$row["pageUrl"], 'title'=>$row["pageTitle"],
								 'score'=> $myResults[$i]["score"]);
			$sql_sel2 =  "select image from Image where pageID=".$myResults[$i]["id"].";";
			$result2 = mysqli_query($con, $sql_sel2);
			$row2 = mysqli_fetch_array($result2);

//			var_dump($row);
//			echo "<br>";
			$hit_result2[] = array('id'=> $myResults[$i]["id"], 'imageUrl'=>$row2['image']);

			$sql_sel3 =  "select info from InfoBox where pageID=".$myResults[$i]["id"].";";
//			$sql_sel3 =  "select info from InfoBox where pageID=33316316;";
			$result3 = mysqli_query($con, $sql_sel3);
			$row3 = mysqli_fetch_array($result3);

//			var_dump($row3);
//			echo "<br>";
//			if($row3){
			$hit_result3[] = array('id'=> $myResults[$i]["id"],'info'=>$row3['info']);
//			}

			$sql_sel4 =  "select category from Category where pageID=".$myResults[$i]["id"].";";
			$result4 = mysqli_query($con, $sql_sel4);
			$tmp_array = array();
			while($row4 = mysqli_fetch_array($result4)){
//				var_dump($row4);
				$tmp_array[] = array('cate'=> $row4['category']);
//				echo "<br>";
			}
//			echo "<br>";
			$hit_result4[] = array('id'=> $myResults[$i]["id"],'cate_array'=>$tmp_array);

//			print($hit_result3[$i]['id']);
//			echo "<br>";
		}
//		var_dump($hit_result4[1]['cate_array']);
		$smarty->assign('web_result', $hit_result);
		$smarty->assign('image_url', $hit_result2);
		$smarty->assign('info_box', $hit_result3);
		$smarty->assign('category', $hit_result4);

		$smarty->display('search_main.tpl');

		mysqli_close($con);
	});


	//**** home(GET)****
	$klein->respond('GET', '/rjyohh/pa6/', function ($request, $response, $service) use ($smarty) {
		$con = mysqli_connect("","group71","group71","group71pa2");
		if (mysqli_connect_errno()) {
			echo "Failed to connect to MySQL: " . mysqli_connect_error();
		}
		$headMsg = "";
		if(!isset($_SESSION['name'])){
			$headMsg = "YOU ARE NOT LOGGED IN!";
			//if not logged in
			$sql= "select albumid, title, username, access from Album where access ='public' order by username;";
			$result = mysqli_query($con, $sql);
			$album_to_unlogged = array();
			while($row = mysqli_fetch_array($result)) {
				$album_to_unlogged[$row['albumid']] = 
				   array("username"=>$row['username'], "title"=> $row['title'], "access"=> $row['access']);
			}
			$smarty->assign('album_to_unlogged',$album_to_unlogged);
		}
		else{
			check_if_expired();
			$headMsg = "Welcome back, ".$_SESSION['name']."!!";
			//if logged in
			$sql = "select albumid, title, username, access from Album where albumid in
			   (select albumid from AlbumAccess where username = '"
			   .$_SESSION['name']."') order by username;";
			$result = mysqli_query($con, $sql);
			$album_to_logged = array();
			while($row = mysqli_fetch_array($result)) {
				$album_to_logged[$row['albumid']] = 
				   array("username"=>$row['username'], "title"=> $row['title'], "access"=>$row['access']);
			}
			$smarty->assign('album_to_logged',$album_to_logged);					
		}
		$smarty->assign('headMsg',$headMsg);
		mysqli_close($con);

		$smarty->display('index.tpl');
	});

	//**** Pic(GET)****
	$klein->respond('GET', '/rjyohh/pa6/pic[:id]?', function ($request, $response, $service) use ($smarty) {
     // Notice how you can set variables here in the PHP that will get carried into the template files
		$picid = $_GET['id'];
		$smarty->assign('picid', $picid);
        // connect DB
		$con = mysqli_connect("","group71","group71","group71pa2");
        // test connection...
		if (mysqli_connect_errno()) {
			echo "Failed to connect to MySQL: " . mysqli_connect_error();
		}

		$sql_sel = "select albumid from Contain where picid ='".$picid."';";
		$result = mysqli_query($con, $sql_sel);
		$row = mysqli_fetch_array($result);
		$albumid = $row['albumid'];

		$state = 0;
		if(isset($_SESSION['name'])){
			check_if_expired();
			$sql_sel = "select username, albumid from AlbumAccess where albumid='" . $albumid. "' and username='".$_SESSION['name']."';";
			$result = mysqli_query($con, $sql_sel);
			if(!mysqli_fetch_array($result)){
				//don't have access
				$state = 1;
			}
		}
		else{
			$state = 1;
			//not logged in
		}
		//when state = 1, the user has no access to private album

		$sql_sel = "select url from Photo where picid ='".$picid."';";
		$result = mysqli_query($con, $sql_sel);
		$row = mysqli_fetch_array($result);
		$pic_url = $row['url'];
		$smarty->assign('pic_url',$pic_url);

		$sql_sel = "select access from Album where albumid='" . $albumid. "';";
		$result = mysqli_query($con, $sql_sel);
		$row = mysqli_fetch_array($result);
		$access = $row['access'];

		if($access == 'private' && $state == 1){ 
			$displayMsg = 'You don\'t have access to see this picture.<br>Please try again after login.';
			$smarty->assign('state', 1);
			$smarty->assign('login_displayMsg', $displayMsg);
			$smarty->assign('prevUrl', '/rjyohh/pa6/pic?id='.$_GET['id']);
			$smarty->display('login.tpl');

		}
		else{
			$sql_sel = "select albumid, caption from Contain where picid = '".$picid ."';"; 
			$result = mysqli_query($con, $sql_sel);
			$row = mysqli_fetch_array($result);
			$albumid = $row['albumid'];
			$caption = $row['caption'];
			$smarty->assign('albumid', $albumid);
			$smarty->assign('caption', $caption);
	
			$sql_sel = "select picid from Contain where albumid = '".$albumid."' 
						AND sequencenum < 
						   (select sequencenum from Contain where picid = '". $picid. "') order by sequencenum DESC limit 1;";
			//select the picid of the previous pic of the current pic ordered by sequencenum
			$result = mysqli_query($con, $sql_sel);
			$row = mysqli_fetch_array($result);
			$prev_picid = $row['picid'];
			$smarty->assign('prev_picid', $prev_picid);
	
				$sql_sel = "select picid from Contain where albumid = '".$albumid."'
						AND sequencenum > 
						   (select sequencenum from Contain where picid = '". $picid. "') order by sequencenum limit 1;";
			//select the picid of the next pic of the current pic ordered by sequencenum
			$result = mysqli_query($con, $sql_sel);
			$row = mysqli_fetch_array($result);
			$next_picid = $row['picid'];
			$smarty->assign('next_picid', $next_picid);
			$smarty->assign('state', 0);

			$smarty->display('pic.tpl');
		}

		mysqli_close($con);
	});
	//****album(GET)****
	$klein->respond('GET', '/rjyohh/pa6/album\?[:id]?', function ($request, $response, $service) use ($smarty) {
		$smarty->assign('albumid', $_GET['id']);
		$con = mysqli_connect("", "group71", "group71", "group71pa2");
		if (mysqli_connect_errno()) {
			echo "Failed to connect to MySQL: " . mysqli_connect_error();
		}

		$sql_sel = "select title, username, access from Album where albumid='" . $_GET['id']. "';";
		$result = mysqli_query($con, $sql_sel);
		$row = mysqli_fetch_array($result);
		$album_title = $row['title'];
		$album_username = $row['username'];
		$album_access = $row['access'];
		$smarty->assign('album_title', $album_title);
		$smarty->assign('album_username', $album_username);
		$smarty->assign('state', 0);

		$state = 0;
		if(isset($_SESSION['name'])){
			check_if_expired();
			$sql_sel = "select username, albumid from AlbumAccess where albumid='" . $_GET['id']. "' and username='".$_SESSION['name']."';";
			$result = mysqli_query($con, $sql_sel);
			if(!mysqli_fetch_array($result)){
				//don't have access
				$state = 1;
			}
		}
		else{
			$state = 1;
			//not logged in
		}
		//when state = 1, the user has no access to private album

		if($row['access'] == 'private' && $state == 1){ 
			$displayMsg = 'You don\'t have access to see this album. <br>Please try again after login.';
			$smarty->assign('login_displayMsg', $displayMsg);
			$smarty->assign('prevUrl', '/rjyohh/pa6/album?id='.$_GET['id']);
			$smarty->display('login.tpl');
		}
		else{
			$sql_sel = "select picid, url, date from Photo where picid in 
						(select picid from Contain where albumid=" . $_GET['id']. " order by sequencenum);";
			$result = mysqli_query($con, $sql_sel);
			$pic_in_album = array();
			while($row = mysqli_fetch_array($result)){
				//mysqli_fetch_array will return row as a array using both 0,1,2, etc or 'picid' as index
				//while mysqli_fetch_row only use 0,1,2...
				$pic_in_album[] = array('url'=>$row['url'], 'date'=>$row['date'], 'picid'=>$row['picid']);
			}
			$caption = array();
			foreach($pic_in_album as $item){
				$sql = "select caption from Contain where picid = '".$item['picid']."';";
				$result = mysqli_query($con, $sql);
				$row = mysqli_fetch_array($result);
				$caption[] = $row['caption'];
			}
			$smarty->assign('pic_in_album', $pic_in_album);
			$smarty->assign('caption', $caption);
			$smarty->display('album.tpl');
		}

		mysqli_close($con);
	});
	//****albums(GET)**** sensitive (GET)
	$klein->respond('GET', '/rjyohh/pa6/albums[:username]?', function ($request, $response, $service) use ($smarty) {
		if(isset($_SESSION['name']) && $_SESSION['name'] === $_GET['username']){
			check_if_expired();
			$smarty->assign('username',$_GET['username']);
			//connect DB
			$con = mysqli_connect("","group71","group71","group71pa2");
			// test connection...
			if (mysqli_connect_errno()) {
			echo "Failed to connect to MySQL: " . mysqli_connect_error();
			}
			$sql_sel = "select albumid, title, access, username from Album where albumid in 
						(select albumid from AlbumAccess where username = '".$_GET['username']."')
						order by access;";
			$result = mysqli_query($con, $sql_sel);

			//Set up an array to store all the title of album;
			$title_access_list = array();
			while($row = mysqli_fetch_array($result)) {
			$title_access_list[$row['albumid']] = array('title' => $row['title'], 
														'access' => $row['access'],
														'username' => $row['username']);
			}
			$smarty->assign('title_access_list',$title_access_list);
			mysqli_close($con);
			$smarty->display('albums.tpl');
		}
		else{
			$problem = 'You are not logged in as '.$_GET['username'].'.<br>
					 	If you want to see '.$_GET['username'].'\'s albums, <br>
						please log in as '.$_GET['username'].'.';
			$smarty->assign('login_displayMsg', $problem);
			$smarty->assign('prevUrl', '/rjyohh/pa6/albums?username='.$_GET['username']);
			$smarty->display('login.tpl');
		}
	});

	//****albums/edit(GET)**** sensitive (GET)
	$klein->respond('GET', '/rjyohh/pa6/albums/edit[:username]?', function($request, $response, $service)use($smarty){
		if(isset($_SESSION['name']) && $_SESSION['name'] === $_GET['username']){
			check_if_expired();
			$con = mysqli_connect("", "group71", "group71", "group71pa2");
			if(mysqli_connect_error()){
				echo "Failed to connect to MySQL: ".mysqli_connect_error();
			}

			$smarty->assign('username',$_GET['username']);
			$sql_sel = "select albumid, title, access from Album where username ='".$_GET['username']."' order by access;";
			$result = mysqli_query($con, $sql_sel);
			$title_access_list = array();
			while($row = mysqli_fetch_array($result)) {
				$title_access_list[$row['albumid']] = array('title'=> $row['title'], 'access'=> $row['access']);
			}
			$smarty->assign('title_access_list',$title_access_list);
			mysqli_close($con);
			$smarty->display('albums_edit.tpl');
		}
		else{
			$problem = 'You are not logged in as '.$_GET['username'].'.<br>
					 	If you want to edit '.$_GET['username'].'\'s albums, <br>
						please log in as '.$_GET['username'].'.';
			$smarty->assign('login_displayMsg', $problem);
			$smarty->assign('prevUrl', '/rjyohh/pa6/albums/edit?username='.$_GET['username']);
			$smarty->display('login.tpl');
		}
	});

   //****album/edit(GET)****
	$klein->respond('GET', '/rjyohh/pa6/album/edit[:id]?', function($request, $response, $service)use($smarty){

		$con = mysqli_connect("", "group71", "group71", "group71pa2");
		if(mysqli_connect_error()){
			echo "Failed to connect to MySQL: ".mysqli_connect_error();
		}

		$sql_sel = "select title, username, access from Album where albumid='" . $_GET['id']. "';";
		$result = mysqli_query($con, $sql_sel);
		$row = mysqli_fetch_array($result);
		$album_title = $row['title'];
		$album_username = $row['username'];
		$album_access = $row['access'];
		$smarty->assign('album_title', $album_title);
		$smarty->assign('album_username', $album_username);
		$smarty->assign('album_access', $row['access']);
		$smarty->assign('albumid', $_GET['id']);
		
		$smarty->assign('state', 0);
		if(isset($_SESSION['name']) && $_SESSION['name'] == $album_username){
			check_if_expired();
			$sql_sel = "select picid, url, date from Photo where picid in 
						(select picid from Contain where albumid=" . $_GET['id']. " order by sequencenum);";
			$result = mysqli_query($con, $sql_sel);
			$pic_in_album = array();
			while($row = mysqli_fetch_array($result)){
				//mysqli_fetch_array will return row as a array using both 0,1,2, etc or 'picid' as index
				//while mysqli_fetch_row only use 0,1,2...
				$pic_in_album[] = array('url'=>$row['url'], 'date'=>$row['date'], 'picid'=>$row['picid']);
			}
			$smarty->assign('pic_in_album', $pic_in_album);

			$caption = array();
			foreach($pic_in_album as $item){
				$sql = "select caption from Contain where picid = '".$item['picid']."';";
				$result = mysqli_query($con, $sql);
				$row = mysqli_fetch_array($result);
				$caption[] = $row['caption'];
			}
			$smarty->assign('caption', $caption);
		}
		else{
			$displayMsg = 'This album is private to '.$row['username'].'. Please log in as '.$row['username'].' if you want to see edit album.';
			$smarty->assign('displayMsg', $displayMsg);
			$smarty->assign('state', 1);
		}


		if($album_access == 'private'){
			$sql_sel = "select username from User where username !='".$album_username."';";
			$result = mysqli_query($con, $sql_sel);
			$user = array();
			while($row = mysqli_fetch_array($result)){
				$user[] = $row['username'];
			}
			$smarty->assign('user', $user);
		}
		
		mysqli_close($con);
		$smarty->display('album_edit.tpl');
	});

	function delete_album($con, $albumid){
		$sql_sel = "select picid from Contain where albumid =".$albumid.";";
 		$result = mysqli_query($con, $sql_sel);
   		$picid_array = array();
   		while($row = mysqli_fetch_array($result)) {
			//echo $row['picid'];
       		$picid_array[] = $row['picid'];
		}	
   		foreach($picid_array as $value){
			delete_pic($con, $value);
   		} 
		$sql_sel = "delete from Contain where albumid =".$albumid.";";
		mysqli_query($con, $sql_sel);

		$sql_sel = "delete from AlbumAccess where albumid =".$albumid.";";
		mysqli_query($con, $sql_sel);

   		$sql_sel = "delete from Album where albumid = ".$albumid.";";
		mysqli_query($con, $sql_sel);
	}


   //****albums/edit(POST)**** sensitive (POST)
   $klein->respond('POST', '/rjyohh/pa6/albums/edit[:username]?', function($request, $response, $service)use($smarty){
		if(isset($_SESSION['name']) && $_SESSION['name'] == $_GET['username']){
   			check_if_expired();
			$con = mysqli_connect("","group71","group71","group71pa2");
        	if (mysqli_connect_errno()) {
            	echo "Failed to connect to MySQL: " . mysqli_connect_error();
        	}

			if($_POST['op']=='delete'){
				delete_album($con, $_POST['albumid']);
			}


			if($_POST['op']=='add'){
				if(!$_POST['title']){
					$_POST['title'] = "Default Album";
				}
				if($_POST['permission']==="public"){
					$permission = "public";
				}
				else{
					$permission = "private";
				}
	    		$today = date("Y-m-d");
	    		$sql_sel = "insert into Album values
				   (DEFAULT,'".$_POST['title']."','".$today
				   ."','".$today."','".$_POST['username']."' ,'".$permission."');";
	    		mysqli_query($con, $sql_sel);
				$albumid = mysqli_insert_id($con);
				if($permission == "public"){
					$sql = "select username from User;";
					$result = mysqli_query($con, $sql);
					$username = array();
					while($row = mysqli_fetch_array($result)){
						$username[] = $row['username'];
					}
					foreach($username as $value){
						$sql= "insert into AlbumAccess values( ".$albumid.", '".$value."')";
						mysqli_query($con, $sql);
					}
				}
				else{
					$sql = "insert into AlbumAccess values( ".$albumid.", '".$_POST['username']."')";
					mysqli_query($con, $sql);
				}
			} 	
			$smarty->assign('username',$_GET['username']);
			$sql_sel = "select albumid, title, access from Album where username ='".$_GET['username']."';";
			$result = mysqli_query($con, $sql_sel);
			$title_access_list = array();
    		while($row = mysqli_fetch_array($result)) {
        		$title_access_list[$row['albumid']] = array('title'=> $row['title'], 'access'=> $row['access']);
    		}	
			$smarty->assign('title_access_list',$title_access_list);
			mysqli_close($con);
			$smarty->display('albums_edit.tpl');
		}
		else{//if not logged in
			$problem = 'You are not logged in as '.$_GET['username'].'.<br>
					 	If you want to edit '.$_GET['username'].'\'s albums, <br>
						please log in as '.$_GET['username'].'.';
			$smarty('login_displayMsg', $problem);
			$prevUrl = "/rjyohh/pa6/albums/edit?username=".$_GET['username'];
			$smarty->display('login.tpl');
		}
   });

	function delete_pic($con, $picid){
			$sql_sel = "select url from Photo where picid ='".$picid."';";
			$result = mysqli_query($con, $sql_sel);
			$row = mysqli_fetch_array($result);
			$delete_pic_url = $row['url'];


			$sql_sel = "select albumid from Contain where picid ='".$picid."';";
			$result = mysqli_query($con, $sql_sel);
			$row = mysqli_fetch_array($result);
			$updated_albumid = $row['albumid'];

			$today = date('Y-m-d');
			$sql_sel = "update Album set lastupdated ='".$today."' where albumid = '".$updated_albumid."';";
			mysqli_query($con, $sql_sel);

			$sql_sel = "delete from Contain where picid = '".$picid."';";
			mysqli_query($con, $sql_sel);

			$sql_sel = "delete from Photo where picid = '".$picid."';";
			mysqli_query($con, $sql_sel);

			unlink(".".$delete_pic_url);
	}

   //****album/edit(POST)**** sensitive (POST)
	$klein->respond('POST', '/rjyohh/pa6/album/edit[:id]?', function($request, $response, $service)use($smarty){
		check_if_expired();
		$con = mysqli_connect("", "group71", "group71", "group71pa2");
		if(mysqli_connect_error()){
			echo "Failed to connect to MySQL: ".mysqli_connect_error();
		}

		$smarty->assign('state', 0);
		//when state is 0, everything works well
		if($_POST['op'] == 'changePermission'){
			$sql = "update Album set access = '".$_POST['permission']."' where albumid = ".$_POST['albumid'].";";
			mysqli_query($con, $sql);
			if($_POST['permission'] == 'private'){
			//change from public to private
				$sql = "delete from AlbumAccess where albumid = " .$_POST['albumid']." and username != '".$_POST['album_username']."';";
				mysqli_query($con, $sql);
			}
			else{
			//change from private to public
				$sql_sel = "select username from User where username != '".$_POST['album_username']."';";
				$result = mysqli_query($con, $sql_sel);
				while($row = mysqli_fetch_array($result)){
					$sql = "insert into AlbumAccess values ('".$_POST['albumid']."' ,'".$row['username']."');";
					mysqli_query($con, $sql);
				}
			}
			$smarty->assign('displayMsg', "Successfully changed the permission of this album to ".$_POST['permission']);
		}

		if($_POST['op'] == 'changeName'){
			$sql = "update Album set title = '".$_POST['newTitle']."' where albumid = ".$_POST['albumid'].";";
			mysqli_query($con, $sql);
			$smarty->assign('displayMsg', "Successfully changed the name of this album to ".$_POST['newTitle']);
		}

		if($_POST['op'] == 'giveAccess'){
			foreach($_POST['user'] as $user){
				$sql = "insert into AlbumAccess values(".$_POST['albumid'].", '". $user."')";
				mysqli_query($con, $sql);
			}
			$smarty->assign('displayMsg', "Successfully give access to those users.");
		}

		if($_POST['op'] == 'delete'){
			delete_pic($con, $_POST['picid']);
			$smarty->assign('displayMsg', "Deleted");
		}

		if($_POST['op'] == 'add'){
			$picid = uniqid("");
			$pic_type = pathinfo($_FILES['newfile']['name'], PATHINFO_EXTENSION);
			$image_dir = "static/pictures/";
			if(move_uploaded_file($_FILES['newfile']['tmp_name'], 
			      $image_dir.$picid.".".$pic_type)){
				$smarty->assign('displayMsg', "Uploaded");
			}
			$today = date('Y-m-d');
			$sql_sel = "insert into Photo values('".$picid."','/".$image_dir.
				   $picid.".".$pic_type.
				   "','".$pic_type."','". 
				   $today."');";
			mysqli_query($con, $sql_sel);

			$sql_sel = "select sequencenum from Contain where albumid = ".$_POST['albumid']." order by sequencenum DESC limit 1;";
			$result = mysqli_query($con, $sql_sel);
			$row = mysqli_fetch_array($result);
			$sequencenum = $row['sequencenum']+1;

			$sql_sel = "insert into Contain values(".$_POST['albumid'].",'".$picid."','UN',".$sequencenum.");";
			mysqli_query($con, $sql_sel);

			$sql_sel = "update Album set lastupdated = '".$today."' where albumid = ".$_POST['albumid'].";";
			mysqli_query($con, $sql_sel);
		}

		$sql_sel = "select title, username, access from Album where albumid='" . $_POST['albumid']. "';";
		$result = mysqli_query($con, $sql_sel);
		$row = mysqli_fetch_array($result);
		$album_title = $row['title'];
		$album_username = $row['username'];
		$album_access = $row['access'];
		$smarty->assign('album_title', $album_title);
		$smarty->assign('album_username', $album_username);
		$smarty->assign('album_access', $row['access']);
		$smarty->assign('albumid', $_POST['albumid']);

		$sql_sel = "select picid, url,date from Photo where picid in 
					(select picid from Contain where albumid=" . $_POST['albumid']. " order by sequencenum);";
		$result = mysqli_query($con, $sql_sel);
		$pic_in_album = array();
		while($row = mysqli_fetch_array($result)){
			$pic_in_album[] = array('picid'=>$row['picid'], 'url' => $row['url'], 'date'=>$row['date']);
		}
		$smarty->assign('pic_in_album', $pic_in_album);

		$caption = array();
		foreach($pic_in_album as $item){
			$sql = "select caption from Contain where picid = '".$item['picid']."';";
			$result = mysqli_query($con, $sql);
			$row = mysqli_fetch_array($result);
			$caption[] = $row['caption'];
		}
		$smarty->assign('caption', $caption);

		if($album_access == 'private'){
			$sql_sel = "select username from User where username !='".$album_username."';";
			$result = mysqli_query($con, $sql_sel);
			$user = array();
			while($row = mysqli_fetch_array($result)){
				$user[] = $row['username'];
			}
			$smarty->assign('user', $user);
		}

		$_POST=array();
		mysqli_close($con);
		$smarty->display('album_edit.tpl');
	});

	//****user(GET)****
	$klein->respond('GET', '/rjyohh/pa6/user', function ($request, $response, $service) use ($smarty) {
		if(!isset($_SESSION['name'])){
			//if not logged in yet
			$smarty->display('user.tpl');
		}
		else{
			check_if_expired();
			//if session exists, redirect to user_edit page
			$url = "Location: user/edit?username=".$_SESSION['name'];
			header($url);
			die;
		}//else
	});

	//****user(POST)****
	$klein->respond('POST', '/rjyohh/pa6/user', function ($request, $response, $service) use ($smarty) {
		$con = mysqli_connect("","group71","group71","group71pa2");
		if (mysqli_connect_errno()) {
			echo "Failed to connect to MySQL: " . mysqli_connect_error();
		}
		$sql = "select password from User where username = '".$_POST['username']."';";
		$result = mysqli_query($con, $sql);
		$row = mysqli_fetch_array($result);
		$displayMsg = "";
		$state = 0;
		if($row){
			$displayMsg = "The username has existed.";
		}
		else{
			if($_POST['pwd'] == $_POST['pwdv']){
				$sql = "insert into User values 
				   ('".$_POST['username']."', '".$_POST['firstname']."',
				    '".$_POST['lastname']."', '".$_POST['pwd']."', 
					'".$_POST['email']."');";
				mysqli_query($con, $sql);
				$sql = "select albumid from Album where access = 'public';";
				$result = mysqli_query($con, $sql);
				while($row = mysqli_fetch_array($result)){
					$sql = "insert into AlbumAccess values(".$row['albumid'].", '".$_POST['username']."');";
					mysqli_query($con, $sql);
				}
				$displayMsg=
				   "Congratuation! You have been successfully registered!";
				$state = 1;
				$_SESSION['name'] = $_POST['username'];
			}
			else{
				$displayMsg = "The passwords must match.";
			}
		}
		$smarty->assign('displayMsg', $displayMsg);
		mysqli_close($con);
		if($state == 0){
			$smarty->display('user.tpl');
		}
		else{
			$response->redirect('/rjyohh/pa6/')->send();
		}
	});
	
	//****user/edit(GET)****
	$klein->respond('GET', '/rjyohh/pa6/user/edit[:username]?', function ($request, $response, $service) use ($smarty) {
		check_if_expired();
		$smarty->assign('username', $_GET['username']);
		$con = mysqli_connect("", "group71", "group71", "group71pa2");
		$sql = "select * from User where username = '". $_GET['username']."';";
		$result = mysqli_query($con, $sql);
		$row = mysqli_fetch_array($result);

		$smarty->assign('firstname', $row['firstname']);
		$smarty->assign('lastname', $row['lastname']);
		$smarty->assign('pwd', $row['password']);
		$smarty->assign('email', $row['email']);
		
		$smarty->display('user_edit.tpl');
	});

	//****user/edit(POST)****
	$klein->respond('POST', '/rjyohh/pa6/user/edit[:username]?', function ($request, $response, $service) use ($smarty) {
		check_if_expired();
		$con = mysqli_connect("","group71","group71","group71pa2");
		if (mysqli_connect_errno()) {
			echo "Failed to connect to MySQL: " . mysqli_connect_error();
		}
		$displayMsg = "";
		if($_POST['pwd'] == $_POST['pwdv']){
			$sql = "update User set firstname = '".$_POST['firstname'].
									"', lastname = '".$_POST['lastname'].
									"', password = '".$_POST['pwd'].
									"', email = '".$_POST['email'].
					"' where username = '".$_POST['username']."';";
			mysqli_query($con, $sql);
			$displayMsg="Your changes to your account have been saved!";
		}
		else{
			$displayMsg = "The passwords must match.";
		}
		$smarty->assign('displayMsg', $displayMsg);
		$smarty->assign('firstname', $_POST['firstname']);
		$smarty->assign('lastname', $_POST['lastname']);
		$smarty->assign('pwd', $_POST['pwd']);
		$smarty->assign('email', $_POST['email']);
		$smarty->assign('username', $_POST['username']);
		mysqli_close($con);
		//$smarty->display('user_edit.tpl');
		$response->redirect('/rjyohh/pa6/')->send();
	});

	//****user/delete(POST)****
	$klein->respond('POST', '/rjyohh/pa6/user/delete[:username]?', function ($request, $response, $service) use ($smarty) {
		check_if_expired();
		$con = mysqli_connect("","group71","group71","group71pa2");
		if (mysqli_connect_errno()) {
			echo "Failed to connect to MySQL: " . mysqli_connect_error();
		}

		//firstly select all the albumid and picid that need to be deleted
		$sql = "select albumid from Album where username = '".$_POST['username']."';";
		$result = mysqli_query($con, $sql);
		//$album_to_delete = array();
		while($row = mysqli_fetch_array($result)){
		//	$album_to_delete[] = $row['albumid'];
		//}
		//foreach($album_to_delete as $item){
			//delete_album($con, $item);
			delete_album($con, $row['albumid']);
		}

		$sql = "delete from AlbumAccess where username = '".$_POST['username']."';";
		mysqli_query($con, $sql);

		//since username is a foreign key in AlbumAccess, 
		//so we need to delete AlbumAccess first!!
		$sql = "delete from User where username = '".$_POST['username']."';";
		mysqli_query($con, $sql);
	
		mysqli_close($con);
		session_destroy();
		$response->redirect('/rjyohh/pa6/')->send();
	});

	//****login(GET)****
	$klein->respond('GET', '/rjyohh/pa6/login', function ($request, $response, $service) use ($smarty) {
		$smarty->assign('prevUrl', '/rjyohh/pa6/');
		$smarty->display('login.tpl');
	});

	//****login(POST)****
	//$klein->respond('POST', '/rjyohh/pa6/login[:prevUrl]?', 
	$klein->respond('POST', '/rjyohh/pa6/login', 
	   function ($request, $response, $service) use ($smarty) {
		$con = mysqli_connect("","group71","group71","group71pa2");
		// test connection...
		if (mysqli_connect_errno()) {
			echo "Failed to connect to MySQL: " . mysqli_connect_error();
		}
		
		$username = $_POST['username'];
		$password = $_POST['pwd'];
		$sql = "select password from User where username = '".$username."';";	
		$result = mysqli_query($con, $sql);
		$row = mysqli_fetch_array($result);
		$problem = "";
		if(!$row['password']){
			$problem = "invalid username";
			$smarty->assign('login_displayMsg', $problem);
			$smarty->assign('prevUrl', $_POST['prevUrl']);
			$smarty->display('login.tpl');
		}
		else{
			if($row['password']== $password){
				$_SESSION['name'] = $username;
				$_SESSION['last_activity'] = time();
//				global $expireMsg = "";	
				$response->redirect($_POST['prevUrl'])->send();
			}
			else{
				$problem = "invalid password";
				$smarty->assign('login_displayMsg', $problem);
				$smarty->assign('prevUrl', $_POST['prevUrl']);
				$smarty->display('login.tpl');
			}
		}
		mysqli_close($con);
	});

	//****Logout Page (GET)****
	$klein->respond('GET', '/rjyohh/pa6/logout', function ($request, $response, $service) use ($smarty) {
		session_destroy();
		$url = "Location: http://eecs485-08.eecs.umich.edu:5671/rjyohh/pa6/";
		header($url);
		exit;
	});
    $klein->dispatch();
//	$smarty->assign('expireMsg', $expireMsg);
?>
