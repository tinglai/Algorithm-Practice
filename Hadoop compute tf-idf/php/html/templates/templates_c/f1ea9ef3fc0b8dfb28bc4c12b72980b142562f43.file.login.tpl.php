<?php /* Smarty version Smarty-3.1.14, created on 2014-11-03 17:53:45
         compiled from "/var/www/html/group71/admin/pa4/php/html/templates/templates/login.tpl" */ ?>
<?php /*%%SmartyHeaderCode:1544384935457e65e2e1633-76110635%%*/if(!defined('SMARTY_DIR')) exit('no direct access allowed');
$_valid = $_smarty_tpl->decodeProperties(array (
  'file_dependency' => 
  array (
    'f1ea9ef3fc0b8dfb28bc4c12b72980b142562f43' => 
    array (
      0 => '/var/www/html/group71/admin/pa4/php/html/templates/templates/login.tpl',
      1 => 1415047320,
      2 => 'file',
    ),
    'f967656063897e85c67fe0b987674c5c679624e7' => 
    array (
      0 => '/var/www/html/group71/admin/pa4/php/html/templates/templates/base.tpl',
      1 => 1415047275,
      2 => 'file',
    ),
  ),
  'nocache_hash' => '1544384935457e65e2e1633-76110635',
  'function' => 
  array (
  ),
  'version' => 'Smarty-3.1.14',
  'unifunc' => 'content_5457e65e3308f2_90292447',
  'variables' => 
  array (
    'title' => 0,
  ),
  'has_nocache_code' => false,
),false); /*/%%SmartyHeaderCode%%*/?>
<?php if ($_valid && !is_callable('content_5457e65e3308f2_90292447')) {function content_5457e65e3308f2_90292447($_smarty_tpl) {?>
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
    		
    <h1 style="font-family: Impact">Login Here</h1>
	<?php if (isset($_smarty_tpl->tpl_vars['login_displayMsg']->value)){?>
	<b><?php echo $_smarty_tpl->tpl_vars['login_displayMsg']->value;?>
</b>
	<?php }?>
    <div>
		<!--<form action ="/rjyohh/pa4/login?prevUrl=<?php echo $_smarty_tpl->tpl_vars['prevUrl']->value;?>
" method = "post">-->
		<form action ="/rjyohh/pa4/login" method = "POST">
			Username: <input type = "text" name = "username"><br>
			Password: <input type = "password" name = "pwd"><br>
			<input type = "hidden" value = <?php echo $_smarty_tpl->tpl_vars['prevUrl']->value;?>
 name = "prevUrl">
			<input type = "submit" value = "Log in" name = "submit">
		</form>
		<p><a href = "/rjyohh/pa4/user">New User? Register Here!</a></p>
		<p><a href = "/rjyohh/pa4/">Just want to look around.</a></p>
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