<?php /* Smarty version Smarty-3.1.14, created on 2014-11-06 23:49:47
         compiled from "/var/www/html/group71/admin/pa4/php/html/templates/templates/albums.tpl" */ ?>
<?php /*%%SmartyHeaderCode:1515239486545c4f6b93bed4-14850931%%*/if(!defined('SMARTY_DIR')) exit('no direct access allowed');
$_valid = $_smarty_tpl->decodeProperties(array (
  'file_dependency' => 
  array (
    '47d188b15430d8c188fc5cc1536bee33b83438ba' => 
    array (
      0 => '/var/www/html/group71/admin/pa4/php/html/templates/templates/albums.tpl',
      1 => 1415047243,
      2 => 'file',
    ),
    'f967656063897e85c67fe0b987674c5c679624e7' => 
    array (
      0 => '/var/www/html/group71/admin/pa4/php/html/templates/templates/base.tpl',
      1 => 1415047275,
      2 => 'file',
    ),
  ),
  'nocache_hash' => '1515239486545c4f6b93bed4-14850931',
  'function' => 
  array (
  ),
  'variables' => 
  array (
    'title' => 0,
  ),
  'has_nocache_code' => false,
  'version' => 'Smarty-3.1.14',
  'unifunc' => 'content_545c4f6b9a6774_86678840',
),false); /*/%%SmartyHeaderCode%%*/?>
<?php if ($_valid && !is_callable('content_545c4f6b9a6774_86678840')) {function content_545c4f6b9a6774_86678840($_smarty_tpl) {?>
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
    		
<?php if (count($_smarty_tpl->tpl_vars['title_access_list']->value)!=0){?>
<h1 align="center">ALBUMS of <?php echo $_smarty_tpl->tpl_vars['username']->value;?>
</h1>
<?php }else{ ?>
<h1>You have no private albums yet</h1>
<?php }?>

<p class="important">
	<table border="1px" width='500' align='center'>
		<thead>
			<tr>
				<th>Album Name</th>
				<th>Owner</th>
				<th>Access</th>
			</tr>
		</thead>
		<tbody>
		<?php  $_smarty_tpl->tpl_vars['value'] = new Smarty_Variable; $_smarty_tpl->tpl_vars['value']->_loop = false;
 $_smarty_tpl->tpl_vars['key'] = new Smarty_Variable;
 $_from = $_smarty_tpl->tpl_vars['title_access_list']->value; if (!is_array($_from) && !is_object($_from)) { settype($_from, 'array');}
foreach ($_from as $_smarty_tpl->tpl_vars['value']->key => $_smarty_tpl->tpl_vars['value']->value){
$_smarty_tpl->tpl_vars['value']->_loop = true;
 $_smarty_tpl->tpl_vars['key']->value = $_smarty_tpl->tpl_vars['value']->key;
?>
			<tr>
				<td><a href= "/rjyohh/pa4/album?id=<?php echo $_smarty_tpl->tpl_vars['key']->value;?>
"><?php echo $_smarty_tpl->tpl_vars['value']->value['title'];?>
</a></td>
				<td align="center"><?php echo $_smarty_tpl->tpl_vars['value']->value['username'];?>
</td>
				<td align="center"><?php echo $_smarty_tpl->tpl_vars['value']->value['access'];?>
</td>
			</tr>
		<?php }
if (!$_smarty_tpl->tpl_vars['value']->_loop) {
?>
		<?php } ?>
		</tbody>
    </table> 
	<a href = "/rjyohh/pa4/" align='center'>Home Page</a> 
</p>

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