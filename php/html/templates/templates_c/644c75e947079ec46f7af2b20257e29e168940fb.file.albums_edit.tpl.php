<?php /* Smarty version Smarty-3.1.14, created on 2014-09-28 20:42:40
         compiled from "/var/www/html/group71/admin/pa2/php/html/templates/templates/albums_edit.tpl" */ ?>
<?php /*%%SmartyHeaderCode:732669888542870d568ed09-03628466%%*/if(!defined('SMARTY_DIR')) exit('no direct access allowed');
$_valid = $_smarty_tpl->decodeProperties(array (
  'file_dependency' => 
  array (
    '644c75e947079ec46f7af2b20257e29e168940fb' => 
    array (
      0 => '/var/www/html/group71/admin/pa2/php/html/templates/templates/albums_edit.tpl',
      1 => 1411950572,
      2 => 'file',
    ),
    'ac410506a7bd37967e256f3a56cdba67acaf5431' => 
    array (
      0 => '/var/www/html/group71/admin/pa2/php/html/templates/templates/base.tpl',
      1 => 1411867949,
      2 => 'file',
    ),
  ),
  'nocache_hash' => '732669888542870d568ed09-03628466',
  'function' => 
  array (
  ),
  'version' => 'Smarty-3.1.14',
  'unifunc' => 'content_542870d56fa9e2_78971363',
  'variables' => 
  array (
    'title' => 0,
  ),
  'has_nocache_code' => false,
),false); /*/%%SmartyHeaderCode%%*/?>
<?php if ($_valid && !is_callable('content_542870d56fa9e2_78971363')) {function content_542870d56fa9e2_78971363($_smarty_tpl) {?>
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
    		
<?php if (count($_smarty_tpl->tpl_vars['title_access_list']->value)!=0){?>
<h1 align="center">ALBUMS of <?php echo $_smarty_tpl->tpl_vars['username']->value;?>
</h1>
<?php }else{ ?>
<h1>You have no private albums yet</h1>
<?php }?>

<p class="important">
        <table border="1px" align='center'>
                <thead>
                        <tr>
                                <th>Album Name</th>
                                <th>Access</th>
                                <th>Edit</th>
                                <th>Delete</th>
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
                                <td><a href= "/rjyohh/pa2/album?id=<?php echo $_smarty_tpl->tpl_vars['key']->value;?>
"><?php echo $_smarty_tpl->tpl_vars['value']->value['title'];?>
</a></td>
                                <td align="center"><?php echo $_smarty_tpl->tpl_vars['value']->value['access'];?>
</td>
                                <td><a href= "/rjyohh/pa2/album/edit?id=<?php echo $_smarty_tpl->tpl_vars['key']->value;?>
">EDIT</a></td>
				<td>
					<form method="POST" action="/rjyohh/pa2/albums/edit?username=<?php echo $_smarty_tpl->tpl_vars['username']->value;?>
">
						<input type="submit" value="DELETE">
						<input type="hidden" name="op" value="delete">
						<input type="hidden" name="albumid" value=<?php echo $_smarty_tpl->tpl_vars['key']->value;?>
>
					</form>
				</td>
                        </tr>
                <?php }
if (!$_smarty_tpl->tpl_vars['value']->_loop) {
?>
                <?php } ?>
                        <tr>
				<td>NEW:__________</td>
				<td>
					<form method="POST" action="/rjyohh/pa2/albums/edit?username=<?php echo $_smarty_tpl->tpl_vars['username']->value;?>
">
						New Album Name: <input type="text" name="title"><br>
						<input type="radio" name="permission" value = "public"> publica<br>
						<input type="radio" name="permission" value = "private"> private<br>
						<input type="hidden" name="op" value="add">
						<input type="hidden" name="username" value="<?php echo $_smarty_tpl->tpl_vars['username']->value;?>
">
						<input type="submit" value = "ADD">
					</form>
				</td>
                        </tr>
                </tbody>
    </table>
        <a href = "/rjyohh/pa2/" align='center'>Home Page</a>
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