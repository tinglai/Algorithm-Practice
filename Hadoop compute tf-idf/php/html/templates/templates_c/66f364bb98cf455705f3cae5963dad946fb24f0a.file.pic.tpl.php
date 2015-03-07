<?php /* Smarty version Smarty-3.1.14, created on 2014-11-03 15:43:15
         compiled from "/var/www/html/group71/admin/pa4/php/html/templates/templates/pic.tpl" */ ?>
<?php /*%%SmartyHeaderCode:434265745457e8e303b677-04941343%%*/if(!defined('SMARTY_DIR')) exit('no direct access allowed');
$_valid = $_smarty_tpl->decodeProperties(array (
  'file_dependency' => 
  array (
    '66f364bb98cf455705f3cae5963dad946fb24f0a' => 
    array (
      0 => '/var/www/html/group71/admin/pa4/php/html/templates/templates/pic.tpl',
      1 => 1415047335,
      2 => 'file',
    ),
    'f967656063897e85c67fe0b987674c5c679624e7' => 
    array (
      0 => '/var/www/html/group71/admin/pa4/php/html/templates/templates/base.tpl',
      1 => 1415047275,
      2 => 'file',
    ),
  ),
  'nocache_hash' => '434265745457e8e303b677-04941343',
  'function' => 
  array (
  ),
  'variables' => 
  array (
    'title' => 0,
  ),
  'has_nocache_code' => false,
  'version' => 'Smarty-3.1.14',
  'unifunc' => 'content_5457e8e30c2410_80652290',
),false); /*/%%SmartyHeaderCode%%*/?>
<?php if ($_valid && !is_callable('content_5457e8e30c2410_80652290')) {function content_5457e8e30c2410_80652290($_smarty_tpl) {?>
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
    		
<p class="important", align="left">
<h1 align = "center">PIC <?php echo $_smarty_tpl->tpl_vars['picid']->value;?>
</h1></td>
<?php if ($_smarty_tpl->tpl_vars['pic_url']->value){?>
	<?php if ($_smarty_tpl->tpl_vars['state']->value==0){?>
		<br>
<!--so all the relative url starts from the website root directory,
which in this case is var/www/html/group/admin/pa4/php/html-->
		<br>
			<table style="margin-top:10px; margin-left:10px;">
			<tr>
				<td></td>
				<td align="center">
					<?php if ($_smarty_tpl->tpl_vars['next_picid']->value!=null){?>
						Click photo to the next page of this album
					<?php }else{ ?>
						Last page of this album
					<?php }?>
				</td>
				<td></td>
			</tr>

			<tr>
				<td></td>
				<?php if ($_smarty_tpl->tpl_vars['next_picid']->value!=null){?>
					<td align="center"><a href="/rjyohh/pa4/pic?id=<?php echo $_smarty_tpl->tpl_vars['next_picid']->value;?>
"><img src="<?php echo $_smarty_tpl->tpl_vars['pic_url']->value;?>
"></a><br>
					Caption: <?php echo $_smarty_tpl->tpl_vars['caption']->value;?>

					</td>
				<?php }else{ ?>
					<td align="center"><img src="<?php echo $_smarty_tpl->tpl_vars['pic_url']->value;?>
"><br>
					Caption: <?php echo $_smarty_tpl->tpl_vars['caption']->value;?>

					</td>
				<?php }?>
				<td></td>
			</tr>

			<tr>
				<td>
					<?php if ($_smarty_tpl->tpl_vars['prev_picid']->value!=null){?>
						<a href="/rjyohh/pa4/pic?id=<?php echo $_smarty_tpl->tpl_vars['prev_picid']->value;?>
">PREV</a>
					<?php }else{ ?>
					First Pic
					<?php }?>
				</td>
				<td align="center">
					<a href="/rjyohh/pa4/album?id=<?php echo $_smarty_tpl->tpl_vars['albumid']->value;?>
">Back To Album</a>
				</td>
				<td>
					<?php if ($_smarty_tpl->tpl_vars['next_picid']->value!=null){?>
						<a href="/rjyohh/pa4/pic?id=<?php echo $_smarty_tpl->tpl_vars['next_picid']->value;?>
">NEXT</a>
					<?php }else{ ?>
						Last Pic
					<?php }?>
				</td>
			</tr>
			</table>
	<?php }else{ ?>
		<p align='center'>
			<?php echo $_smarty_tpl->tpl_vars['displayMsg']->value;?>
<br>
			<a href="/rjyohh/pa4/login">Login Here</a>&nbsp;&nbsp;&nbsp;
			<a href="/rjyohh/pa4/">Back To Home Page</a>
		</p>
	<?php }?>
<?php }else{ ?>
<h1>PIC <?php echo $_smarty_tpl->tpl_vars['picid']->value;?>
 Not Found</h1>
<?php }?>
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