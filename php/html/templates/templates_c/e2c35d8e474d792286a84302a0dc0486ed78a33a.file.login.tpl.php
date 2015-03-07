<?php /* Smarty version Smarty-3.1.14, created on 2014-09-29 18:59:09
         compiled from "/var/www/html/group71/admin/pa2/php/html/templates/templates/login.tpl" */ ?>
<?php /*%%SmartyHeaderCode:805598852542448e7ecfb47-67265792%%*/if(!defined('SMARTY_DIR')) exit('no direct access allowed');
$_valid = $_smarty_tpl->decodeProperties(array (
  'file_dependency' => 
  array (
    'e2c35d8e474d792286a84302a0dc0486ed78a33a' => 
    array (
      0 => '/var/www/html/group71/admin/pa2/php/html/templates/templates/login.tpl',
      1 => 1412030850,
      2 => 'file',
    ),
    'ac410506a7bd37967e256f3a56cdba67acaf5431' => 
    array (
      0 => '/var/www/html/group71/admin/pa2/php/html/templates/templates/base.tpl',
      1 => 1411867949,
      2 => 'file',
    ),
  ),
  'nocache_hash' => '805598852542448e7ecfb47-67265792',
  'function' => 
  array (
  ),
  'version' => 'Smarty-3.1.14',
  'unifunc' => 'content_542448e7f00569_92731206',
  'variables' => 
  array (
    'title' => 0,
  ),
  'has_nocache_code' => false,
),false); /*/%%SmartyHeaderCode%%*/?>
<?php if ($_valid && !is_callable('content_542448e7f00569_92731206')) {function content_542448e7f00569_92731206($_smarty_tpl) {?>
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
    		
    <h1 style="font-family: Impact">Login Here</h1>
	<?php if (isset($_smarty_tpl->tpl_vars['login_displayMsg']->value)){?>
	<b><?php echo $_smarty_tpl->tpl_vars['login_displayMsg']->value;?>
</b>
	<?php }?>
    <div>
		<!--<form action ="/rjyohh/pa2/login?prevUrl=<?php echo $_smarty_tpl->tpl_vars['prevUrl']->value;?>
" method = "post">-->
		<form action ="/rjyohh/pa2/login" method = "POST">
			Username: <input type = "text" name = "username"><br>
			Password: <input type = "password" name = "pwd"><br>
			<input type = "hidden" value = <?php echo $_smarty_tpl->tpl_vars['prevUrl']->value;?>
 name = "prevUrl">
			<input type = "submit" value = "Log in" name = "submit">
		</form>
		<p><a href = "/rjyohh/pa2/user">New User? Register Here!</a></p>
		<p><a href = "/rjyohh/pa2/">Just want to look around.</a></p>
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