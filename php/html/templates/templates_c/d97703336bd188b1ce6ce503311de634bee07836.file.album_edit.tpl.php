<?php /* Smarty version Smarty-3.1.14, created on 2014-10-02 15:30:20
         compiled from "/var/www/html/group71/admin/pa2/php/html/templates/templates/album_edit.tpl" */ ?>
<?php /*%%SmartyHeaderCode:2936891725428c0d06c7954-60755046%%*/if(!defined('SMARTY_DIR')) exit('no direct access allowed');
$_valid = $_smarty_tpl->decodeProperties(array (
  'file_dependency' => 
  array (
    'd97703336bd188b1ce6ce503311de634bee07836' => 
    array (
      0 => '/var/www/html/group71/admin/pa2/php/html/templates/templates/album_edit.tpl',
      1 => 1412036846,
      2 => 'file',
    ),
    'ac410506a7bd37967e256f3a56cdba67acaf5431' => 
    array (
      0 => '/var/www/html/group71/admin/pa2/php/html/templates/templates/base.tpl',
      1 => 1411867949,
      2 => 'file',
    ),
  ),
  'nocache_hash' => '2936891725428c0d06c7954-60755046',
  'function' => 
  array (
  ),
  'version' => 'Smarty-3.1.14',
  'unifunc' => 'content_5428c0d075f8a9_45332460',
  'variables' => 
  array (
    'title' => 0,
  ),
  'has_nocache_code' => false,
),false); /*/%%SmartyHeaderCode%%*/?>
<?php if ($_valid && !is_callable('content_5428c0d075f8a9_45332460')) {function content_5428c0d075f8a9_45332460($_smarty_tpl) {?>
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
    		
<?php if ($_smarty_tpl->tpl_vars['album_title']->value!=null){?>
	<h1 align="center"><?php echo $_smarty_tpl->tpl_vars['album_title']->value;?>
</h1>
	<h2 align="center">Owner: <?php echo $_smarty_tpl->tpl_vars['album_username']->value;?>
</h2>
	<?php if ($_smarty_tpl->tpl_vars['state']->value==0){?>
		<?php if (isset($_smarty_tpl->tpl_vars['displayMsg']->value)){?>
			<p><?php echo $_smarty_tpl->tpl_vars['displayMsg']->value;?>
</p>
		<?php }?>
		<p class="important">
		    <table border="1" align="center">
				<tr>
					<td colspan=3 align = 'center'>
<!--album title-->
					<form action="/rjyohh/pa2/album/edit?id=<?php echo $_smarty_tpl->tpl_vars['albumid']->value;?>
" method="POST">
						Chage Album Name :<input type = "text", name = "newTitle">
						<input type = "submit" value = "Change">
						<input type="hidden" name='op' value="changeName">
						<input type="hidden" name='albumid' value="<?php echo $_smarty_tpl->tpl_vars['albumid']->value;?>
">
					</form>
					</td>
				</tr>
				<tr>
<!--permission-->
					<td colspan=3 align = 'center'>
					<form action="/rjyohh/pa2/album/edit?id=<?php echo $_smarty_tpl->tpl_vars['albumid']->value;?>
" method="POST">
						Chage Album's Permission:
						<input type = "radio", name = "permission" value = 'public'> public
						<input type = "radio" name = "permission" value = 'private'> private
						<input type = "submit" value = 'Change'>
						<input type="hidden" name='op' value="changePermission">
						<input type="hidden" name='album_username' value="<?php echo $_smarty_tpl->tpl_vars['album_username']->value;?>
">
						<input type="hidden" name='albumid' value="<?php echo $_smarty_tpl->tpl_vars['albumid']->value;?>
">
					</form>
					</td>
				</tr>

				<?php ob_start();?><?php echo count($_smarty_tpl->tpl_vars['pic_in_album']->value);?>
<?php $_tmp1=ob_get_clean();?><?php $_smarty_tpl->tpl_vars['i'] = new Smarty_Variable;$_smarty_tpl->tpl_vars['i']->step = 1;$_smarty_tpl->tpl_vars['i']->total = (int)ceil(($_smarty_tpl->tpl_vars['i']->step > 0 ? ceil(($_tmp1)/3)-1+1 - (0) : 0-(ceil(($_tmp1)/3)-1)+1)/abs($_smarty_tpl->tpl_vars['i']->step));
if ($_smarty_tpl->tpl_vars['i']->total > 0){
for ($_smarty_tpl->tpl_vars['i']->value = 0, $_smarty_tpl->tpl_vars['i']->iteration = 1;$_smarty_tpl->tpl_vars['i']->iteration <= $_smarty_tpl->tpl_vars['i']->total;$_smarty_tpl->tpl_vars['i']->value += $_smarty_tpl->tpl_vars['i']->step, $_smarty_tpl->tpl_vars['i']->iteration++){
$_smarty_tpl->tpl_vars['i']->first = $_smarty_tpl->tpl_vars['i']->iteration == 1;$_smarty_tpl->tpl_vars['i']->last = $_smarty_tpl->tpl_vars['i']->iteration == $_smarty_tpl->tpl_vars['i']->total;?>
<!--delete-->
				<tr>
					<?php $_smarty_tpl->tpl_vars['j'] = new Smarty_Variable;$_smarty_tpl->tpl_vars['j']->step = 1;$_smarty_tpl->tpl_vars['j']->total = (int)ceil(($_smarty_tpl->tpl_vars['j']->step > 0 ? 2+1 - (0) : 0-(2)+1)/abs($_smarty_tpl->tpl_vars['j']->step));
if ($_smarty_tpl->tpl_vars['j']->total > 0){
for ($_smarty_tpl->tpl_vars['j']->value = 0, $_smarty_tpl->tpl_vars['j']->iteration = 1;$_smarty_tpl->tpl_vars['j']->iteration <= $_smarty_tpl->tpl_vars['j']->total;$_smarty_tpl->tpl_vars['j']->value += $_smarty_tpl->tpl_vars['j']->step, $_smarty_tpl->tpl_vars['j']->iteration++){
$_smarty_tpl->tpl_vars['j']->first = $_smarty_tpl->tpl_vars['j']->iteration == 1;$_smarty_tpl->tpl_vars['j']->last = $_smarty_tpl->tpl_vars['j']->iteration == $_smarty_tpl->tpl_vars['j']->total;?>
						<?php if ($_smarty_tpl->tpl_vars['i']->value*3+$_smarty_tpl->tpl_vars['j']->value<count($_smarty_tpl->tpl_vars['pic_in_album']->value)){?>
						<td>
							<a href="/rjyohh/pa2/pic?id=<?php echo $_smarty_tpl->tpl_vars['pic_in_album']->value[$_smarty_tpl->tpl_vars['i']->value*3+$_smarty_tpl->tpl_vars['j']->value]['picid'];?>
">
							<img src = "<?php echo $_smarty_tpl->tpl_vars['pic_in_album']->value[$_smarty_tpl->tpl_vars['i']->value*3+$_smarty_tpl->tpl_vars['j']->value]['url'];?>
" width="200" height="200">
							</a>
							<br>
							Caption: <?php echo $_smarty_tpl->tpl_vars['caption']->value[$_smarty_tpl->tpl_vars['i']->value*3+$_smarty_tpl->tpl_vars['j']->value];?>

							<br>
							Created on: <?php echo $_smarty_tpl->tpl_vars['pic_in_album']->value[$_smarty_tpl->tpl_vars['i']->value*3+$_smarty_tpl->tpl_vars['j']->value]['date'];?>

							<br>
							<form action="/rjyohh/pa2/album/edit?id=<?php echo $_smarty_tpl->tpl_vars['albumid']->value;?>
" method="POST">
								<input type="hidden" name='op' value="delete">
								<input type="hidden" name='albumid' value="<?php echo $_smarty_tpl->tpl_vars['albumid']->value;?>
">
								<input type="hidden" name='picid' value="<?php echo $_smarty_tpl->tpl_vars['pic_in_album']->value[$_smarty_tpl->tpl_vars['i']->value*3+$_smarty_tpl->tpl_vars['j']->value]['picid'];?>
">
								<input type="submit" value="Delete">
							</form>
						</td>
						<?php }?>
					<?php }} ?>
				</tr>
				<?php }} ?>
				<tr>
					<td colspan=3 align="center">Upload:</td>
				</tr>
				<tr>
<!--add-->
					<td colspan=3 align="center">
						<form enctype="multipart/form-data" action="/rjyohh/pa2/album/edit?id=<?php echo $_smarty_tpl->tpl_vars['albumid']->value;?>
" method="POST">
							<input type="hidden" name="MAX_FILE_SIZE" value="300000000">
							<input type="file" name="newfile">
							<input type="hidden" name="op" value="add">
							<input type="hidden" name="albumid" value=<?php echo $_smarty_tpl->tpl_vars['albumid']->value;?>
>
							<input type="submit" value="Submit">
						</form>
					</td>
				</tr>

<!--give access-->
				<?php if ($_smarty_tpl->tpl_vars['album_access']->value=='private'){?>


                    <tr>
                        <td colspan=3 align='left'>
						Give Access to:<br>
                        </td>
                    </tr>
 					<?php ob_start();?><?php echo count($_smarty_tpl->tpl_vars['user']->value);?>
<?php $_tmp2=ob_get_clean();?><?php $_smarty_tpl->tpl_vars['i'] = new Smarty_Variable;$_smarty_tpl->tpl_vars['i']->step = 1;$_smarty_tpl->tpl_vars['i']->total = (int)ceil(($_smarty_tpl->tpl_vars['i']->step > 0 ? ceil(($_tmp2)/3)-1+1 - (0) : 0-(ceil(($_tmp2)/3)-1)+1)/abs($_smarty_tpl->tpl_vars['i']->step));
if ($_smarty_tpl->tpl_vars['i']->total > 0){
for ($_smarty_tpl->tpl_vars['i']->value = 0, $_smarty_tpl->tpl_vars['i']->iteration = 1;$_smarty_tpl->tpl_vars['i']->iteration <= $_smarty_tpl->tpl_vars['i']->total;$_smarty_tpl->tpl_vars['i']->value += $_smarty_tpl->tpl_vars['i']->step, $_smarty_tpl->tpl_vars['i']->iteration++){
$_smarty_tpl->tpl_vars['i']->first = $_smarty_tpl->tpl_vars['i']->iteration == 1;$_smarty_tpl->tpl_vars['i']->last = $_smarty_tpl->tpl_vars['i']->iteration == $_smarty_tpl->tpl_vars['i']->total;?>
                    <tr>
					<form action="/rjyohh/pa2/album/edit?id=<?php echo $_smarty_tpl->tpl_vars['albumid']->value;?>
" method="POST">
                    <?php $_smarty_tpl->tpl_vars['j'] = new Smarty_Variable;$_smarty_tpl->tpl_vars['j']->step = 1;$_smarty_tpl->tpl_vars['j']->total = (int)ceil(($_smarty_tpl->tpl_vars['j']->step > 0 ? 2+1 - (0) : 0-(2)+1)/abs($_smarty_tpl->tpl_vars['j']->step));
if ($_smarty_tpl->tpl_vars['j']->total > 0){
for ($_smarty_tpl->tpl_vars['j']->value = 0, $_smarty_tpl->tpl_vars['j']->iteration = 1;$_smarty_tpl->tpl_vars['j']->iteration <= $_smarty_tpl->tpl_vars['j']->total;$_smarty_tpl->tpl_vars['j']->value += $_smarty_tpl->tpl_vars['j']->step, $_smarty_tpl->tpl_vars['j']->iteration++){
$_smarty_tpl->tpl_vars['j']->first = $_smarty_tpl->tpl_vars['j']->iteration == 1;$_smarty_tpl->tpl_vars['j']->last = $_smarty_tpl->tpl_vars['j']->iteration == $_smarty_tpl->tpl_vars['j']->total;?>
                        <?php if ($_smarty_tpl->tpl_vars['i']->value*3+$_smarty_tpl->tpl_vars['j']->value<count($_smarty_tpl->tpl_vars['user']->value)){?> 
                        <td>
							<input type = "checkbox", value='<?php echo $_smarty_tpl->tpl_vars['user']->value[$_smarty_tpl->tpl_vars['i']->value*3+$_smarty_tpl->tpl_vars['j']->value];?>
' name = "user[]"> <?php echo $_smarty_tpl->tpl_vars['user']->value[$_smarty_tpl->tpl_vars['i']->value*3+$_smarty_tpl->tpl_vars['j']->value];?>

                        </td>
                        <?php }?>
                    <?php }} ?>
                    </tr>
					<?php }} ?>
					<tr>
						<input type="hidden" name='op' value="giveAccess">
						<input type="hidden" name='albumid' value="<?php echo $_smarty_tpl->tpl_vars['albumid']->value;?>
">
						<input type="hidden" name='album_username' value="<?php echo $_smarty_tpl->tpl_vars['album_username']->value;?>
">
					<td>
						<input type = "submit" value = "Submit">
					</td>
					</form>
					</tr>
				<?php }?>
				<tr>
					<td colspam=3 align="center">
						<a href="/rjyohh/pa2/albums/edit?username=<?php echo $_smarty_tpl->tpl_vars['album_username']->value;?>
">Back To My Albums</a>
					</td>
				</tr>
			</table>
		</p>
	<?php }else{ ?>
		<p><?php echo $_smarty_tpl->tpl_vars['displayMsg']->value;?>
</p>
	<?php }?>
<?php }else{ ?>
<h1>Could not find ALBUM with albumid <?php echo $_smarty_tpl->tpl_vars['albumid']->value;?>
</h1>
<?php }?>

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