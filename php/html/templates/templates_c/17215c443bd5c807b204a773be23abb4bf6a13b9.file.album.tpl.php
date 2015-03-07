<?php /* Smarty version Smarty-3.1.14, created on 2014-09-19 16:29:04
         compiled from "/var/www/html/group71/admin/pa1/php/html/templates/templates/album.tpl" */ ?>
<?php /*%%SmartyHeaderCode:122899975254164a781449a5-96823205%%*/if(!defined('SMARTY_DIR')) exit('no direct access allowed');
$_valid = $_smarty_tpl->decodeProperties(array (
  'file_dependency' => 
  array (
    '17215c443bd5c807b204a773be23abb4bf6a13b9' => 
    array (
      0 => '/var/www/html/group71/admin/pa1/php/html/templates/templates/album.tpl',
      1 => 1411157344,
      2 => 'file',
    ),
    '2c4147c8b19f33c33a846f7bd0b1af94ee42124d' => 
    array (
      0 => '/var/www/html/group71/admin/pa1/php/html/templates/templates/base.tpl',
      1 => 1411156757,
      2 => 'file',
    ),
  ),
  'nocache_hash' => '122899975254164a781449a5-96823205',
  'function' => 
  array (
  ),
  'version' => 'Smarty-3.1.14',
  'unifunc' => 'content_54164a78174f74_44950343',
  'variables' => 
  array (
    'title' => 0,
  ),
  'has_nocache_code' => false,
),false); /*/%%SmartyHeaderCode%%*/?>
<?php if ($_valid && !is_callable('content_54164a78174f74_44950343')) {function content_54164a78174f74_44950343($_smarty_tpl) {?>

<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01//EN">
<html lang="en">
<head>

    <link rel="stylesheet" href="/static/css/style.css" />

    <title><?php echo $_smarty_tpl->tpl_vars['title']->value;?>
</title>
</head>
<body>
  <div class="center">
    
<?php if ($_smarty_tpl->tpl_vars['album_title']->value!=null){?>
<h1 align="center"><?php echo $_smarty_tpl->tpl_vars['album_title']->value;?>
</h1>
<p class="important">
    <table border="1" align="center">
		<?php ob_start();?><?php echo count($_smarty_tpl->tpl_vars['pic_url_in_album']->value);?>
<?php $_tmp1=ob_get_clean();?><?php $_smarty_tpl->tpl_vars['i'] = new Smarty_Variable;$_smarty_tpl->tpl_vars['i']->step = 1;$_smarty_tpl->tpl_vars['i']->total = (int)ceil(($_smarty_tpl->tpl_vars['i']->step > 0 ? ceil(($_tmp1)/3)-1+1 - (0) : 0-(ceil(($_tmp1)/3)-1)+1)/abs($_smarty_tpl->tpl_vars['i']->step));
if ($_smarty_tpl->tpl_vars['i']->total > 0){
for ($_smarty_tpl->tpl_vars['i']->value = 0, $_smarty_tpl->tpl_vars['i']->iteration = 1;$_smarty_tpl->tpl_vars['i']->iteration <= $_smarty_tpl->tpl_vars['i']->total;$_smarty_tpl->tpl_vars['i']->value += $_smarty_tpl->tpl_vars['i']->step, $_smarty_tpl->tpl_vars['i']->iteration++){
$_smarty_tpl->tpl_vars['i']->first = $_smarty_tpl->tpl_vars['i']->iteration == 1;$_smarty_tpl->tpl_vars['i']->last = $_smarty_tpl->tpl_vars['i']->iteration == $_smarty_tpl->tpl_vars['i']->total;?>
        	<tr>
			<?php $_smarty_tpl->tpl_vars['j'] = new Smarty_Variable;$_smarty_tpl->tpl_vars['j']->step = 1;$_smarty_tpl->tpl_vars['j']->total = (int)ceil(($_smarty_tpl->tpl_vars['j']->step > 0 ? 2+1 - (0) : 0-(2)+1)/abs($_smarty_tpl->tpl_vars['j']->step));
if ($_smarty_tpl->tpl_vars['j']->total > 0){
for ($_smarty_tpl->tpl_vars['j']->value = 0, $_smarty_tpl->tpl_vars['j']->iteration = 1;$_smarty_tpl->tpl_vars['j']->iteration <= $_smarty_tpl->tpl_vars['j']->total;$_smarty_tpl->tpl_vars['j']->value += $_smarty_tpl->tpl_vars['j']->step, $_smarty_tpl->tpl_vars['j']->iteration++){
$_smarty_tpl->tpl_vars['j']->first = $_smarty_tpl->tpl_vars['j']->iteration == 1;$_smarty_tpl->tpl_vars['j']->last = $_smarty_tpl->tpl_vars['j']->iteration == $_smarty_tpl->tpl_vars['j']->total;?>
				<?php if ($_smarty_tpl->tpl_vars['i']->value*3+$_smarty_tpl->tpl_vars['j']->value<count($_smarty_tpl->tpl_vars['pic_url_in_album']->value)){?>
				<td>
				<a href="/rjyohh/pa1/pic?id=<?php echo $_smarty_tpl->tpl_vars['picid_in_album']->value[$_smarty_tpl->tpl_vars['i']->value*3+$_smarty_tpl->tpl_vars['j']->value];?>
">
				<img src = "<?php echo $_smarty_tpl->tpl_vars['pic_url_in_album']->value[$_smarty_tpl->tpl_vars['i']->value*3+$_smarty_tpl->tpl_vars['j']->value];?>
" width="200" height="200">
				</a>
				<br>
				<form action="/rjyohh/pa1/album/edit?id=<?php echo $_smarty_tpl->tpl_vars['albumid']->value;?>
" method="POST">
					<input type="hidden" name='op' value="delete">
					<input type="hidden" name='albumid' value="<?php echo $_smarty_tpl->tpl_vars['albumid']->value;?>
">
					<input type="hidden" name='picid' value="<?php echo $_smarty_tpl->tpl_vars['picid_in_album']->value[$_smarty_tpl->tpl_vars['i']->value*3+$_smarty_tpl->tpl_vars['j']->value];?>
">
					<input type="submit" value="Delete">
				</form>
				</td>
				<?php }?>
			<?php }} ?>
        	</tr>
		<?php }} ?>
		<tr>
		<td colspan=3 align="center">Upload:</td>
		</tr>
		<tr>
			<td colspan=3 align="center">
			<form enctype="multipart/form-data" action="/rjyohh/pa1/album/edit?id=<?php echo $_smarty_tpl->tpl_vars['albumid']->value;?>
" method="POST">
				<input type="hidden" name="MAX_FILE_SIZE" value="300000000">
				<input type="file" name="newfile">
				<input type="hidden" name="op" value="add">
				<input type="hidden" name="albumid" value=<?php echo $_smarty_tpl->tpl_vars['albumid']->value;?>
>
				<input type="submit" value="Submit">
			</form>
			</td>
		</tr>
		<tr>
			<td colspam=3 align="center">
				<a href="/rjyohh/pa1/albums?username=<?php echo $_smarty_tpl->tpl_vars['album_username']->value;?>
">Back To Albums</a>
			</td>
		</tr>
	</table>
</p>
<?php }else{ ?>
<h1>Could not find ALBUM with albumid <?php echo $_smarty_tpl->tpl_vars['albumid']->value;?>
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