<?php /* Smarty version Smarty-3.1.14, created on 2014-11-06 14:07:53
         compiled from "/var/www/html/group71/admin/pa4/php/html/templates/templates/index.tpl" */ ?>
<?php /*%%SmartyHeaderCode:6079544065457e662311303-50251736%%*/if(!defined('SMARTY_DIR')) exit('no direct access allowed');
$_valid = $_smarty_tpl->decodeProperties(array (
  'file_dependency' => 
  array (
    'f5ad97ffc20e5d3eaabac106e529eab243a1be64' => 
    array (
      0 => '/var/www/html/group71/admin/pa4/php/html/templates/templates/index.tpl',
      1 => 1415300871,
      2 => 'file',
    ),
    'f967656063897e85c67fe0b987674c5c679624e7' => 
    array (
      0 => '/var/www/html/group71/admin/pa4/php/html/templates/templates/base.tpl',
      1 => 1415047275,
      2 => 'file',
    ),
  ),
  'nocache_hash' => '6079544065457e662311303-50251736',
  'function' => 
  array (
  ),
  'version' => 'Smarty-3.1.14',
  'unifunc' => 'content_5457e662386bd5_52691624',
  'variables' => 
  array (
    'title' => 0,
  ),
  'has_nocache_code' => false,
),false); /*/%%SmartyHeaderCode%%*/?>
<?php if ($_valid && !is_callable('content_5457e662386bd5_52691624')) {function content_5457e662386bd5_52691624($_smarty_tpl) {?>
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
    		
	<h1 style="font-family: Impact">User based Album System</h1>
	<div>
    	<p style="font-size:20px; font-family: Impact">website brief introduction</p><br>
	</div>
	<div>
    	<h4 style="font-family: Arial"><?php echo $_smarty_tpl->tpl_vars['headMsg']->value;?>
</h4>
		<table border = "1px">
			<thead>
				<tr>
					<th colspan= "3">All Ablums You Can See</th>
				</tr>
				<tr>
					<th>Album Name</th>
					<th>Owner</th>
					<th>Access</th>
				</tr>
			</thead>
			<tbody>

			<?php if (isset($_SESSION['name'])){?>
          	<?php  $_smarty_tpl->tpl_vars['value'] = new Smarty_Variable; $_smarty_tpl->tpl_vars['value']->_loop = false;
 $_smarty_tpl->tpl_vars['key'] = new Smarty_Variable;
 $_from = $_smarty_tpl->tpl_vars['album_to_logged']->value; if (!is_array($_from) && !is_object($_from)) { settype($_from, 'array');}
foreach ($_from as $_smarty_tpl->tpl_vars['value']->key => $_smarty_tpl->tpl_vars['value']->value){
$_smarty_tpl->tpl_vars['value']->_loop = true;
 $_smarty_tpl->tpl_vars['key']->value = $_smarty_tpl->tpl_vars['value']->key;
?>
             	<tr>
					<td><a href= "/rjyohh/pa4/album?id=<?php echo $_smarty_tpl->tpl_vars['key']->value;?>
"><?php echo $_smarty_tpl->tpl_vars['value']->value['title'];?>
</a></td>
					<td><?php echo $_smarty_tpl->tpl_vars['value']->value['username'];?>
</td>
					<td><?php echo $_smarty_tpl->tpl_vars['value']->value['access'];?>
</td>
				</tr>
          	<?php }
if (!$_smarty_tpl->tpl_vars['value']->_loop) {
?>
	  		<?php } ?>

			<?php }else{ ?>
          	<?php  $_smarty_tpl->tpl_vars['value'] = new Smarty_Variable; $_smarty_tpl->tpl_vars['value']->_loop = false;
 $_smarty_tpl->tpl_vars['key'] = new Smarty_Variable;
 $_from = $_smarty_tpl->tpl_vars['album_to_unlogged']->value; if (!is_array($_from) && !is_object($_from)) { settype($_from, 'array');}
foreach ($_from as $_smarty_tpl->tpl_vars['value']->key => $_smarty_tpl->tpl_vars['value']->value){
$_smarty_tpl->tpl_vars['value']->_loop = true;
 $_smarty_tpl->tpl_vars['key']->value = $_smarty_tpl->tpl_vars['value']->key;
?>
             	<tr>
					<td><a href= "/rjyohh/pa4/album?id=<?php echo $_smarty_tpl->tpl_vars['key']->value;?>
"><?php echo $_smarty_tpl->tpl_vars['value']->value['title'];?>
</a></td>
					<td><?php echo $_smarty_tpl->tpl_vars['value']->value['username'];?>
</td>
					<td><?php echo $_smarty_tpl->tpl_vars['value']->value['access'];?>
</td>
				</tr>
          	<?php }
if (!$_smarty_tpl->tpl_vars['value']->_loop) {
?>
	  		<?php } ?>
			<?php }?>	
			</tbody>
      	</table>
		<p>
			<?php if (!isset($_SESSION['name'])){?>
				<a href = "/rjyohh/pa4/login">Log In</a><br>
			<?php }?>
			<a href = "/rjyohh/pa4/user">Register and Join</a><br>
			<a href = "/rjyohh/pa4/search">Search Pictures!</a><br>
		</p>
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