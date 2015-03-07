<?php /* Smarty version Smarty-3.1.14, created on 2014-09-19 16:01:13
         compiled from "/var/www/html/group71/admin/pa1/php/html/templates/templates/index.tpl" */ ?>
<?php /*%%SmartyHeaderCode:7073068825414d7d70cd3a4-06423156%%*/if(!defined('SMARTY_DIR')) exit('no direct access allowed');
$_valid = $_smarty_tpl->decodeProperties(array (
  'file_dependency' => 
  array (
    '4886116bbc76ad8bf6cbbc021819f8ae1db4ce87' => 
    array (
      0 => '/var/www/html/group71/admin/pa1/php/html/templates/templates/index.tpl',
      1 => 1410806454,
      2 => 'file',
    ),
    '2c4147c8b19f33c33a846f7bd0b1af94ee42124d' => 
    array (
      0 => '/var/www/html/group71/admin/pa1/php/html/templates/templates/base.tpl',
      1 => 1411156757,
      2 => 'file',
    ),
  ),
  'nocache_hash' => '7073068825414d7d70cd3a4-06423156',
  'function' => 
  array (
  ),
  'version' => 'Smarty-3.1.14',
  'unifunc' => 'content_5414d7d7109351_60463833',
  'variables' => 
  array (
    'title' => 0,
  ),
  'has_nocache_code' => false,
),false); /*/%%SmartyHeaderCode%%*/?>
<?php if ($_valid && !is_callable('content_5414d7d7109351_60463833')) {function content_5414d7d7109351_60463833($_smarty_tpl) {?>

<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01//EN">
<html lang="en">
<head>

    <link rel="stylesheet" href="/static/css/style.css" />

    <title><?php echo $_smarty_tpl->tpl_vars['title']->value;?>
</title>
</head>
<body>
  <div class="center">
    
  <h1 style="font-family: Impact">User based Album System</h1>
  <div>
    <p style="font-size:20px; font-family: Impact">website brief introduction</p>
  </div>
  <div>
    <h4 style="font-family: Arial">User's List</h4>
      <ul style="font-family: Arial">
          <?php  $_smarty_tpl->tpl_vars['value'] = new Smarty_Variable; $_smarty_tpl->tpl_vars['value']->_loop = false;
 $_smarty_tpl->tpl_vars['key'] = new Smarty_Variable;
 $_from = $_smarty_tpl->tpl_vars['username_array']->value; if (!is_array($_from) && !is_object($_from)) { settype($_from, 'array');}
foreach ($_from as $_smarty_tpl->tpl_vars['value']->key => $_smarty_tpl->tpl_vars['value']->value){
$_smarty_tpl->tpl_vars['value']->_loop = true;
 $_smarty_tpl->tpl_vars['key']->value = $_smarty_tpl->tpl_vars['value']->key;
?>
             <li><a href= "/rjyohh/pa1/albums?username=<?php echo $_smarty_tpl->tpl_vars['value']->value;?>
"><?php echo $_smarty_tpl->tpl_vars['value']->value;?>
</a></li>
          <?php }
if (!$_smarty_tpl->tpl_vars['value']->_loop) {
?>
	  <?php } ?>
      </ul>
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