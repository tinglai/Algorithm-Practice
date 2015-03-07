<?php /* Smarty version Smarty-3.1.14, created on 2014-09-29 17:24:45
         compiled from "/var/www/html/group71/admin/pa2/php/html/templates/templates/pic.tpl" */ ?>
<?php /*%%SmartyHeaderCode:79075522154237284ad0783-13332198%%*/if(!defined('SMARTY_DIR')) exit('no direct access allowed');
$_valid = $_smarty_tpl->decodeProperties(array (
  'file_dependency' => 
  array (
    '751b8390695551b4940069005d821d9ca7689be3' => 
    array (
      0 => '/var/www/html/group71/admin/pa2/php/html/templates/templates/pic.tpl',
      1 => 1412025882,
      2 => 'file',
    ),
    'ac410506a7bd37967e256f3a56cdba67acaf5431' => 
    array (
      0 => '/var/www/html/group71/admin/pa2/php/html/templates/templates/base.tpl',
      1 => 1411867949,
      2 => 'file',
    ),
  ),
  'nocache_hash' => '79075522154237284ad0783-13332198',
  'function' => 
  array (
  ),
  'version' => 'Smarty-3.1.14',
  'unifunc' => 'content_54237284b41327_57627512',
  'variables' => 
  array (
    'title' => 0,
  ),
  'has_nocache_code' => false,
),false); /*/%%SmartyHeaderCode%%*/?>
<?php if ($_valid && !is_callable('content_54237284b41327_57627512')) {function content_54237284b41327_57627512($_smarty_tpl) {?>
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
    		
<p class="important", align="left">
<h1 align = "center">PIC <?php echo $_smarty_tpl->tpl_vars['picid']->value;?>
</h1></td>
<?php if ($_smarty_tpl->tpl_vars['pic_url']->value){?>
	<?php if ($_smarty_tpl->tpl_vars['state']->value==0){?>
		<br>
<!--so all the relative url starts from the website root directory,
which in this case is var/www/html/group/admin/pa2/php/html-->
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
					<td align="center"><a href="/rjyohh/pa2/pic?id=<?php echo $_smarty_tpl->tpl_vars['next_picid']->value;?>
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
						<a href="/rjyohh/pa2/pic?id=<?php echo $_smarty_tpl->tpl_vars['prev_picid']->value;?>
">PREV</a>
					<?php }else{ ?>
					First Pic
					<?php }?>
				</td>
				<td align="center">
					<a href="/rjyohh/pa2/album?id=<?php echo $_smarty_tpl->tpl_vars['albumid']->value;?>
">Back To Album</a>
				</td>
				<td>
					<?php if ($_smarty_tpl->tpl_vars['next_picid']->value!=null){?>
						<a href="/rjyohh/pa2/pic?id=<?php echo $_smarty_tpl->tpl_vars['next_picid']->value;?>
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
			<a href="/rjyohh/pa2/login">Login Here</a>&nbsp;&nbsp;&nbsp;
			<a href="/rjyohh/pa2/">Back To Home Page</a>
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