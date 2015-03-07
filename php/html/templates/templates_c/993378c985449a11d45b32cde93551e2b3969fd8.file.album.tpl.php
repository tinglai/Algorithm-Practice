<?php /* Smarty version Smarty-3.1.14, created on 2014-12-06 01:39:20
         compiled from "/var/www/html/group71/admin/pa6/php/html/templates/templates/album.tpl" */ ?>
<?php /*%%SmartyHeaderCode:2196265185482a49875b3a9-25151152%%*/if(!defined('SMARTY_DIR')) exit('no direct access allowed');
$_valid = $_smarty_tpl->decodeProperties(array (
  'file_dependency' => 
  array (
    '993378c985449a11d45b32cde93551e2b3969fd8' => 
    array (
      0 => '/var/www/html/group71/admin/pa6/php/html/templates/templates/album.tpl',
      1 => 1415333568,
      2 => 'file',
    ),
    '4f19271ef9d176b7919b6d8a9e0b9d25b13d66e0' => 
    array (
      0 => '/var/www/html/group71/admin/pa6/php/html/templates/templates/base.tpl',
      1 => 1415047275,
      2 => 'file',
    ),
  ),
  'nocache_hash' => '2196265185482a49875b3a9-25151152',
  'function' => 
  array (
  ),
  'variables' => 
  array (
    'title' => 0,
  ),
  'has_nocache_code' => false,
  'version' => 'Smarty-3.1.14',
  'unifunc' => 'content_5482a498810398_53910974',
),false); /*/%%SmartyHeaderCode%%*/?>
<?php if ($_valid && !is_callable('content_5482a498810398_53910974')) {function content_5482a498810398_53910974($_smarty_tpl) {?>
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
				<li><a href = "/rjyohh/pa4/">Home</a></li>
				<li><a href = "/rjyohh/pa4/user/edit?username=<?php echo $_SESSION['name'];?>
">Edit Account</a></li>
				<li><a href = "/rjyohh/pa4/albums/edit?username=<?php echo $_SESSION['name'];?>
">My Albums</a></li>
				<li><a href = "/rjyohh/pa4/logout">Logout</a></li>
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
</p><br>
		<?php }else{ ?>
			<p class="important">
			<?php ob_start();?><?php echo count($_smarty_tpl->tpl_vars['pic_in_album']->value);?>
<?php $_tmp1=ob_get_clean();?><?php if ($_tmp1==0){?>
				<p align = 'center'><b>There are no photos in this album right now.</b></p>
			<?php }else{ ?>
			    <table border="1" align="center">
					<?php ob_start();?><?php echo count($_smarty_tpl->tpl_vars['pic_in_album']->value);?>
<?php $_tmp2=ob_get_clean();?><?php $_smarty_tpl->tpl_vars['i'] = new Smarty_Variable;$_smarty_tpl->tpl_vars['i']->step = 1;$_smarty_tpl->tpl_vars['i']->total = (int)ceil(($_smarty_tpl->tpl_vars['i']->step > 0 ? ceil(($_tmp2)/3)-1+1 - (0) : 0-(ceil(($_tmp2)/3)-1)+1)/abs($_smarty_tpl->tpl_vars['i']->step));
if ($_smarty_tpl->tpl_vars['i']->total > 0){
for ($_smarty_tpl->tpl_vars['i']->value = 0, $_smarty_tpl->tpl_vars['i']->iteration = 1;$_smarty_tpl->tpl_vars['i']->iteration <= $_smarty_tpl->tpl_vars['i']->total;$_smarty_tpl->tpl_vars['i']->value += $_smarty_tpl->tpl_vars['i']->step, $_smarty_tpl->tpl_vars['i']->iteration++){
$_smarty_tpl->tpl_vars['i']->first = $_smarty_tpl->tpl_vars['i']->iteration == 1;$_smarty_tpl->tpl_vars['i']->last = $_smarty_tpl->tpl_vars['i']->iteration == $_smarty_tpl->tpl_vars['i']->total;?>
			        	<tr>
						<?php $_smarty_tpl->tpl_vars['j'] = new Smarty_Variable;$_smarty_tpl->tpl_vars['j']->step = 1;$_smarty_tpl->tpl_vars['j']->total = (int)ceil(($_smarty_tpl->tpl_vars['j']->step > 0 ? 2+1 - (0) : 0-(2)+1)/abs($_smarty_tpl->tpl_vars['j']->step));
if ($_smarty_tpl->tpl_vars['j']->total > 0){
for ($_smarty_tpl->tpl_vars['j']->value = 0, $_smarty_tpl->tpl_vars['j']->iteration = 1;$_smarty_tpl->tpl_vars['j']->iteration <= $_smarty_tpl->tpl_vars['j']->total;$_smarty_tpl->tpl_vars['j']->value += $_smarty_tpl->tpl_vars['j']->step, $_smarty_tpl->tpl_vars['j']->iteration++){
$_smarty_tpl->tpl_vars['j']->first = $_smarty_tpl->tpl_vars['j']->iteration == 1;$_smarty_tpl->tpl_vars['j']->last = $_smarty_tpl->tpl_vars['j']->iteration == $_smarty_tpl->tpl_vars['j']->total;?>
							<?php if ($_smarty_tpl->tpl_vars['i']->value*3+$_smarty_tpl->tpl_vars['j']->value<count($_smarty_tpl->tpl_vars['pic_in_album']->value)){?>
							<td>
							<a href="/rjyohh/pa4/pic?id=<?php echo $_smarty_tpl->tpl_vars['pic_in_album']->value[$_smarty_tpl->tpl_vars['i']->value*3+$_smarty_tpl->tpl_vars['j']->value]['picid'];?>
">
							<img src = "<?php echo $_smarty_tpl->tpl_vars['pic_in_album']->value[$_smarty_tpl->tpl_vars['i']->value*3+$_smarty_tpl->tpl_vars['j']->value]['url'];?>
" width="200" height="200">
							</a>
							<br>
							Caption: <?php echo $_smarty_tpl->tpl_vars['caption']->value[$_smarty_tpl->tpl_vars['i']->value*3+$_smarty_tpl->tpl_vars['j']->value];?>

							<br>
							Created on: <?php echo $_smarty_tpl->tpl_vars['pic_in_album']->value[$_smarty_tpl->tpl_vars['i']->value*3+$_smarty_tpl->tpl_vars['j']->value]['date'];?>

							</td>
							<?php }?>
						<?php }} ?>
			        	</tr>
					<?php }} ?>
				</table>
			<?php }?>
				<p align = 'center'>
					<?php if (!isset($_SESSION['name'])){?>
					<a href="/rjyohh/pa4/">Back To All Albums</a>
					<?php }else{ ?>
					<a href="/rjyohh/pa4/albums?username=<?php echo $_SESSION['name'];?>
">Back To My Albums</a>
					<?php }?>
				</p>
			</p>
		<?php }?>
	<?php }else{ ?>
			<p align='center'><?php echo $_smarty_tpl->tpl_vars['displayMsg']->value;?>
</p><br>
			<p align='center' ><a href="/rjyohh/pa4/">Back To Home Page</a></p>
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