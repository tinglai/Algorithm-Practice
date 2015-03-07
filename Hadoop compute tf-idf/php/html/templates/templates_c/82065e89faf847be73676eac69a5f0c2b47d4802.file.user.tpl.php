<?php /* Smarty version Smarty-3.1.14, created on 2014-10-02 15:29:26
         compiled from "/var/www/html/group71/admin/pa2/php/html/templates/templates/user.tpl" */ ?>
<?php /*%%SmartyHeaderCode:1063052234542437b298f0e7-51006952%%*/if(!defined('SMARTY_DIR')) exit('no direct access allowed');
$_valid = $_smarty_tpl->decodeProperties(array (
  'file_dependency' => 
  array (
    '82065e89faf847be73676eac69a5f0c2b47d4802' => 
    array (
      0 => '/var/www/html/group71/admin/pa2/php/html/templates/templates/user.tpl',
      1 => 1412219432,
      2 => 'file',
    ),
    'ac410506a7bd37967e256f3a56cdba67acaf5431' => 
    array (
      0 => '/var/www/html/group71/admin/pa2/php/html/templates/templates/base.tpl',
      1 => 1411867949,
      2 => 'file',
    ),
  ),
  'nocache_hash' => '1063052234542437b298f0e7-51006952',
  'function' => 
  array (
  ),
  'version' => 'Smarty-3.1.14',
  'unifunc' => 'content_542437b29c0a12_74955846',
  'variables' => 
  array (
    'title' => 0,
  ),
  'has_nocache_code' => false,
),false); /*/%%SmartyHeaderCode%%*/?>
<?php if ($_valid && !is_callable('content_542437b29c0a12_74955846')) {function content_542437b29c0a12_74955846($_smarty_tpl) {?>
<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01//EN">
<html lang="en">
<head>

    <link rel="stylesheet" href="/static/css/style.css" />

    <title><?php echo $_smarty_tpl->tpl_vars['title']->value;?>
</title>

</head>
<body class = "center">
	<div id= "container">

	<?php if (isset($_SESSION['name'])){?>
		<div id ="header" >
			<ul id= "navi">
				<li><a href = "/rjyohh/pa2/">Home</a></li>
				<li><a href = "/rjyohh/pa2/user/edit?username=<?php echo $_SESSION['name'];?>
">Edit Account</a></li>
				<li><a href = "/rjyohh/pa2/albums/edit?username=<?php echo $_SESSION['name'];?>
">My Albums</a></li>
				<li><a href = "/rjyohh/pa2/logout">Logout</a></li>
			</ul>
		</div>
		logged in as <?php echo $_SESSION['name'];?>

	<?php }?>
		<div id="main">
    		
    <h1 style="font-family: Impact">Register Page</h1>
    <div>
		<?php if (isset($_smarty_tpl->tpl_vars['displayMsg']->value)){?>
			<p><?php echo $_smarty_tpl->tpl_vars['displayMsg']->value;?>
</p><br>
		<?php }?>
		<form action ="/rjyohh/pa2/user" method = "post">
			Username(*): <input type = "text" name = "username" required 
			   pattern ="[A-Za-z0-9_]{3,}" 
			   title = "At least 3 character long & only letter, digit and underscore allowed"><br>
			First name: <input type = "text" name = "firstname" ><br>
			Last name: <input type = "text" name = "lastname"><br>
			E-mail address(*): <input type = "email" name = "email" required><br>
		   	Password(*): <input type = "password" id = "pwd" name = "pwd" required 
				   pattern ="(?=(.*[0-9]+))(?=(.*[A-Za-z]+))[0-9A-Za-z_]{5,15}"
	   
			   title = "5-15 characters long & only letter, digit and underscore allowed. At least one character and one digit"><br>
			Password verification(*): <input type = "password" id = "pwdv" name = "pwdv" required 
				   pattern ="(?=(.*[0-9]+))(?=(.*[A-Za-z]+))[0-9A-Za-z_]{5,15}"
			   title = "5-15 characters long & only letter, digit and underscore allowed. At least one character and one digit"><br>

			<!--following JS checks if passwords match-->
			<script type="text/javascript">
			
			var elem = document.getElementById("pwdv");
			elem.addEventListener("blur", verifyPassword);
			function verifyPassword(){
				if(document.getElementById("pwd").value != document.getElementById("pwdv").value){
					document.getElementById("pwdv").setCustomValidity('The passwords don\'t  match!');
				}
				else{
					document.getElementById("pwdv").setCustomValidity('');
				}
			}
			
			</script>

			<input type = "submit" name = "submit" value = "Submit">
		</form>

		<p><a href = "/rjyohh/pa2/login">Login Now!</a></p>
    </div>

		</div>
	</div>
	<script type="text/javascript" src="/static/js/main.js"></script>
</body>
<footer class = "center">
	<p align = "center">Posted by: Jiawei and Ting</p>
	<p align = "center">Contact information:<br><a href="mailto:wangjiaw@umich.edu">wangjiaw@umich.edu</a>
	<br><a href="mailto:laiting@umich.edu">laiting@umich.edu</a><br></p>
</footer>
</html>
<?php }} ?>