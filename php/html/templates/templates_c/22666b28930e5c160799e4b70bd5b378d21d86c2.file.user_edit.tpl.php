<?php /* Smarty version Smarty-3.1.14, created on 2014-11-03 17:53:58
         compiled from "/var/www/html/group71/admin/pa4/php/html/templates/templates/user_edit.tpl" */ ?>
<?php /*%%SmartyHeaderCode:92752028854580786e8f396-95163945%%*/if(!defined('SMARTY_DIR')) exit('no direct access allowed');
$_valid = $_smarty_tpl->decodeProperties(array (
  'file_dependency' => 
  array (
    '22666b28930e5c160799e4b70bd5b378d21d86c2' => 
    array (
      0 => '/var/www/html/group71/admin/pa4/php/html/templates/templates/user_edit.tpl',
      1 => 1415047361,
      2 => 'file',
    ),
    'f967656063897e85c67fe0b987674c5c679624e7' => 
    array (
      0 => '/var/www/html/group71/admin/pa4/php/html/templates/templates/base.tpl',
      1 => 1415047275,
      2 => 'file',
    ),
  ),
  'nocache_hash' => '92752028854580786e8f396-95163945',
  'function' => 
  array (
  ),
  'variables' => 
  array (
    'title' => 0,
  ),
  'has_nocache_code' => false,
  'version' => 'Smarty-3.1.14',
  'unifunc' => 'content_54580786ef65d1_46545813',
),false); /*/%%SmartyHeaderCode%%*/?>
<?php if ($_valid && !is_callable('content_54580786ef65d1_46545813')) {function content_54580786ef65d1_46545813($_smarty_tpl) {?>
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
    		
<h1 style="font-family: Impact">Edit Your Account</h1>
******here you can edit your account******
	<div>
		<?php if (isset($_smarty_tpl->tpl_vars['displayMsg']->value)){?>
			<p><b><?php echo $_smarty_tpl->tpl_vars['displayMsg']->value;?>
</b></p><br>
		<?php }?>
	<table>
	<tr>
		<form action="/rjyohh/pa4/user/edit?username=<?php echo $_smarty_tpl->tpl_vars['username']->value;?>
" method="POST">
			<tr>
				<td>First name: <input type = "text" name = "firstname" value = "<?php echo $_smarty_tpl->tpl_vars['firstname']->value;?>
"><br></td>
			</tr>
			<tr>
				<td>Last name: <input type = "text" name = "lastname" value = "<?php echo $_smarty_tpl->tpl_vars['lastname']->value;?>
"><br></td>
			</tr>
			<tr>
				<td>E-mail address: <input type = "email" name = "email" value = "<?php echo $_smarty_tpl->tpl_vars['email']->value;?>
" required><br></td>
			</tr>
			<!-- Password(*): <input type = "password" id = "pwd" name = "pwd" 
			required pattern ="[A-Za-z]{1,}[0-9]{1,}[_]" 
			-->
			<tr>
				<td>
					Password: <input type = "password" id = "pwd" name = "pwd" value = "<?php echo $_smarty_tpl->tpl_vars['pwd']->value;?>
"
				   		required pattern ="(?=(.*[0-9]+))(?=(.*[A-Za-z]+))[0-9A-Za-z_]{5,15}"
					    title = "5-15 characters long & only letter, digit and underscore allowed at least one letter and one digit"><br>
				</td>
			</tr>
			<tr>
				<td>
					Password verification(*): <input type = "password" id = "pwdv" name = "pwdv" value = "<?php echo $_smarty_tpl->tpl_vars['pwdv']->value;?>
"
				   		required pattern ="(?=(.*[0-9]+))(?=(.*[A-Za-z]+))[0-9A-Za-z_]{5,15}"
						title = "5-15 characters long & only letter, digit and underscore allowed at least one letter and one digit"><br>
				</td>
			</tr>

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
			<tr>
				<td><input type = "hidden" name = "username" value = <?php echo $_smarty_tpl->tpl_vars['username']->value;?>
></td>
			</tr>
			<tr>
				<td><input type = "submit" name = "submit" value = "SUBMIT"></td>
			</tr>
        </form>
	</tr>
	<tr>
		<td>
			<form action = "/rjyohh/pa4/user/delete?username=<?php echo $_smarty_tpl->tpl_vars['username']->value;?>
" method = "POST">
            	<input type = "hidden" name = "username" value = <?php echo $_smarty_tpl->tpl_vars['username']->value;?>
>
				<input type = "submit" value = "DELETE">
			</form>
		</td>
	</tr>
	</table>
        <p><a href = "/rjyohh/pa4/login">Login Now!</a></p>
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