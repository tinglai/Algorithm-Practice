<?php /* Smarty version Smarty-3.1.14, created on 2014-09-19 16:00:05
         compiled from "/var/www/html/group71/admin/pa1/php/html/templates/templates/pic.tpl" */ ?>
<?php /*%%SmartyHeaderCode:201241562854165a0782df87-88463722%%*/if(!defined('SMARTY_DIR')) exit('no direct access allowed');
$_valid = $_smarty_tpl->decodeProperties(array (
  'file_dependency' => 
  array (
    '439be52545ea28dd9728ba5fedb81d2d6c30285f' => 
    array (
      0 => '/var/www/html/group71/admin/pa1/php/html/templates/templates/pic.tpl',
      1 => 1410978981,
      2 => 'file',
    ),
    '2c4147c8b19f33c33a846f7bd0b1af94ee42124d' => 
    array (
      0 => '/var/www/html/group71/admin/pa1/php/html/templates/templates/base.tpl',
      1 => 1411156757,
      2 => 'file',
    ),
  ),
  'nocache_hash' => '201241562854165a0782df87-88463722',
  'function' => 
  array (
  ),
  'version' => 'Smarty-3.1.14',
  'unifunc' => 'content_54165a0785ff44_60776768',
  'variables' => 
  array (
    'title' => 0,
  ),
  'has_nocache_code' => false,
),false); /*/%%SmartyHeaderCode%%*/?>
<?php if ($_valid && !is_callable('content_54165a0785ff44_60776768')) {function content_54165a0785ff44_60776768($_smarty_tpl) {?>

<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01//EN">
<html lang="en">
<head>

    <link rel="stylesheet" href="/static/css/style.css" />

    <title><?php echo $_smarty_tpl->tpl_vars['title']->value;?>
</title>
</head>
<body>
  <div class="center">
    
<p class="important", align="left">
<?php if ($_smarty_tpl->tpl_vars['pic_url']->value){?>
<br>
<!--so all the relative url starts from the website root directory,
which in this case is var/www/html/group/admin/pa1/php/html-->
<br>
<table style="margin-top:10px; margin-left:10px;">
	<tr>
			<td></td>
			<td align = "center"><h1>PIC <?php echo $_smarty_tpl->tpl_vars['picid']->value;?>
</h1></td>
			<td></td>
	</tr>
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
				<td align="center"><a href="/rjyohh/pa1/pic?id=<?php echo $_smarty_tpl->tpl_vars['next_picid']->value;?>
"><img src="<?php echo $_smarty_tpl->tpl_vars['pic_url']->value;?>
"></a></td>
			<?php }else{ ?>
				<td align="center"><img src="<?php echo $_smarty_tpl->tpl_vars['pic_url']->value;?>
"></td>
			<?php }?>
			<td></td>
	</tr>

	<tr>
		<td>
			<?php if ($_smarty_tpl->tpl_vars['prev_picid']->value!=null){?>
				<a href="/rjyohh/pa1/pic?id=<?php echo $_smarty_tpl->tpl_vars['prev_picid']->value;?>
">PREV</a>
			<?php }else{ ?>
				First Pic
			<?php }?>
		</td>
		<td align="center">
			<a href="/rjyohh/pa1/album?id=<?php echo $_smarty_tpl->tpl_vars['albumid']->value;?>
">Back To Album</a>
		</td>
		<td>
			<?php if ($_smarty_tpl->tpl_vars['next_picid']->value!=null){?>
				<a href="/rjyohh/pa1/pic?id=<?php echo $_smarty_tpl->tpl_vars['next_picid']->value;?>
">NEXT</a>
			<?php }else{ ?>
				Last Pic
			<?php }?>
		</td>
	</tr>
</table>
<?php }else{ ?>
<h1>PIC <?php echo $_smarty_tpl->tpl_vars['picid']->value;?>
 Not Found</h1>
<?php }?>
</p>

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