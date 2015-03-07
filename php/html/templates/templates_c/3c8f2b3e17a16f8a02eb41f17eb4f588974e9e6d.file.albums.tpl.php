<?php /* Smarty version Smarty-3.1.14, created on 2014-09-19 15:59:55
         compiled from "/var/www/html/group71/admin/pa1/php/html/templates/templates/albums.tpl" */ ?>
<?php /*%%SmartyHeaderCode:153162157154164a7c02fc16-62389596%%*/if(!defined('SMARTY_DIR')) exit('no direct access allowed');
$_valid = $_smarty_tpl->decodeProperties(array (
  'file_dependency' => 
  array (
    '3c8f2b3e17a16f8a02eb41f17eb4f588974e9e6d' => 
    array (
      0 => '/var/www/html/group71/admin/pa1/php/html/templates/templates/albums.tpl',
      1 => 1410984150,
      2 => 'file',
    ),
    '2c4147c8b19f33c33a846f7bd0b1af94ee42124d' => 
    array (
      0 => '/var/www/html/group71/admin/pa1/php/html/templates/templates/base.tpl',
      1 => 1411156757,
      2 => 'file',
    ),
  ),
  'nocache_hash' => '153162157154164a7c02fc16-62389596',
  'function' => 
  array (
  ),
  'version' => 'Smarty-3.1.14',
  'unifunc' => 'content_54164a7c060693_15829760',
  'variables' => 
  array (
    'title' => 0,
  ),
  'has_nocache_code' => false,
),false); /*/%%SmartyHeaderCode%%*/?>
<?php if ($_valid && !is_callable('content_54164a7c060693_15829760')) {function content_54164a7c060693_15829760($_smarty_tpl) {?>

<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01//EN">
<html lang="en">
<head>

    <link rel="stylesheet" href="/static/css/style.css" />

    <title><?php echo $_smarty_tpl->tpl_vars['title']->value;?>
</title>
</head>
<body>
  <div class="center">
    
<?php if (count($_smarty_tpl->tpl_vars['title_array']->value)!=0){?>
<h1 align="center">ALBUMS of <?php echo $_smarty_tpl->tpl_vars['username']->value;?>
</h1>
<p class="important">
	<table border="1px">
		<thead>
			<tr>
				<th colspan="3">the albums of <?php echo $_smarty_tpl->tpl_vars['username']->value;?>
</th>
			</tr>
			<tr>
				<th>Album Name</th>
				<th>Edit</th>
				<th>Delete</th>
			</tr>
		</thead>
		<tbody>
		<?php  $_smarty_tpl->tpl_vars['value'] = new Smarty_Variable; $_smarty_tpl->tpl_vars['value']->_loop = false;
 $_smarty_tpl->tpl_vars['key'] = new Smarty_Variable;
 $_from = $_smarty_tpl->tpl_vars['title_array']->value; if (!is_array($_from) && !is_object($_from)) { settype($_from, 'array');}
foreach ($_from as $_smarty_tpl->tpl_vars['value']->key => $_smarty_tpl->tpl_vars['value']->value){
$_smarty_tpl->tpl_vars['value']->_loop = true;
 $_smarty_tpl->tpl_vars['key']->value = $_smarty_tpl->tpl_vars['value']->key;
?>
			<tr>
				<td><a href= "/rjyohh/pa1/album?id=<?php echo $_smarty_tpl->tpl_vars['key']->value;?>
"><?php echo $_smarty_tpl->tpl_vars['value']->value;?>
</a></td>
				<td><a href= "/rjyohh/pa1/album/edit?id=<?php echo $_smarty_tpl->tpl_vars['key']->value;?>
">[Edit]</a></td>
				<td>
					<form action="/rjyohh/pa1/albums/edit?username=<?php echo $_smarty_tpl->tpl_vars['username']->value;?>
" method= "post">
						<input type = "hidden" value = <?php echo $_smarty_tpl->tpl_vars['username']->value;?>
 name = "username">
						<input type = "hidden" value = <?php echo $_smarty_tpl->tpl_vars['key']->value;?>
 name = "albumid">
						<input type = "hidden" value = "delete" name = "op">
						<input type = "submit" value = "Delete">
					</form>
				</td>     
			</tr>
		<?php }
if (!$_smarty_tpl->tpl_vars['value']->_loop) {
?>
		<?php } ?>
                
			<tr>
				<td>New:_______</td>
				<td>
					<form action="/rjyohh/pa1/albums/edit?username=<?php echo $_smarty_tpl->tpl_vars['username']->value;?>
" method= "post">
						Album Title:<input type = "text" name = "title"><br>
						<input type = "hidden" value = <?php echo $_smarty_tpl->tpl_vars['username']->value;?>
 name = "username">
						<input type = "hidden" value = "add" name = "op">
						<input type = "submit" value = "Add">
					</form>
				</td>
			</tr>
		</tbody>
    </table> 
	<a href = "/rjyohh/pa1/">Home Page</a> 
</p>
<?php }else{ ?>
<h1>Could Not Find ALBUMS of <?php echo $_smarty_tpl->tpl_vars['username']->value;?>
</h1>
<?php }?>

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