<?php /* Smarty version Smarty-3.1.14, created on 2014-11-07 17:44:59
         compiled from "/var/www/html/group71/admin/pa4/php/html/templates/templates/search_main.tpl" */ ?>
<?php /*%%SmartyHeaderCode:5277216165457f0f4325381-54731196%%*/if(!defined('SMARTY_DIR')) exit('no direct access allowed');
$_valid = $_smarty_tpl->decodeProperties(array (
  'file_dependency' => 
  array (
    '51a86a2139917b36284bb0d1c170cc8bdecdc3ce' => 
    array (
      0 => '/var/www/html/group71/admin/pa4/php/html/templates/templates/search_main.tpl',
      1 => 1415400295,
      2 => 'file',
    ),
    'f967656063897e85c67fe0b987674c5c679624e7' => 
    array (
      0 => '/var/www/html/group71/admin/pa4/php/html/templates/templates/base.tpl',
      1 => 1415047275,
      2 => 'file',
    ),
  ),
  'nocache_hash' => '5277216165457f0f4325381-54731196',
  'function' => 
  array (
  ),
  'version' => 'Smarty-3.1.14',
  'unifunc' => 'content_5457f0f436bcb4_93161080',
  'variables' => 
  array (
    'title' => 0,
  ),
  'has_nocache_code' => false,
),false); /*/%%SmartyHeaderCode%%*/?>
<?php if ($_valid && !is_callable('content_5457f0f436bcb4_93161080')) {function content_5457f0f436bcb4_93161080($_smarty_tpl) {?>
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
    		
    <h1 style="font-family: Impact">Search Box</h1>
    <div>
		<?php ob_start();?><?php echo count($_smarty_tpl->tpl_vars['pic_result']->value);?>
<?php $_tmp1=ob_get_clean();?><?php if ($_tmp1==0){?>
			<p><b>NO Search Result!</b></p>
		<?php }else{ ?>
			<p>BY CLICK THE PIC, FIND THE SIMILAR PIC!</p>
			<p>Number of Search Result: <?php echo count($_smarty_tpl->tpl_vars['pic_result']->value);?>
</p>
 			<table border="1" align="center">
 				<?php ob_start();?><?php echo count($_smarty_tpl->tpl_vars['pic_result']->value);?>
<?php $_tmp2=ob_get_clean();?><?php $_smarty_tpl->tpl_vars['i'] = new Smarty_Variable;$_smarty_tpl->tpl_vars['i']->step = 1;$_smarty_tpl->tpl_vars['i']->total = (int)ceil(($_smarty_tpl->tpl_vars['i']->step > 0 ? ceil(($_tmp2)/3)-1+1 - (0) : 0-(ceil(($_tmp2)/3)-1)+1)/abs($_smarty_tpl->tpl_vars['i']->step));
if ($_smarty_tpl->tpl_vars['i']->total > 0){
for ($_smarty_tpl->tpl_vars['i']->value = 0, $_smarty_tpl->tpl_vars['i']->iteration = 1;$_smarty_tpl->tpl_vars['i']->iteration <= $_smarty_tpl->tpl_vars['i']->total;$_smarty_tpl->tpl_vars['i']->value += $_smarty_tpl->tpl_vars['i']->step, $_smarty_tpl->tpl_vars['i']->iteration++){
$_smarty_tpl->tpl_vars['i']->first = $_smarty_tpl->tpl_vars['i']->iteration == 1;$_smarty_tpl->tpl_vars['i']->last = $_smarty_tpl->tpl_vars['i']->iteration == $_smarty_tpl->tpl_vars['i']->total;?>
					<tr>
						<?php $_smarty_tpl->tpl_vars['j'] = new Smarty_Variable;$_smarty_tpl->tpl_vars['j']->step = 1;$_smarty_tpl->tpl_vars['j']->total = (int)ceil(($_smarty_tpl->tpl_vars['j']->step > 0 ? 2+1 - (0) : 0-(2)+1)/abs($_smarty_tpl->tpl_vars['j']->step));
if ($_smarty_tpl->tpl_vars['j']->total > 0){
for ($_smarty_tpl->tpl_vars['j']->value = 0, $_smarty_tpl->tpl_vars['j']->iteration = 1;$_smarty_tpl->tpl_vars['j']->iteration <= $_smarty_tpl->tpl_vars['j']->total;$_smarty_tpl->tpl_vars['j']->value += $_smarty_tpl->tpl_vars['j']->step, $_smarty_tpl->tpl_vars['j']->iteration++){
$_smarty_tpl->tpl_vars['j']->first = $_smarty_tpl->tpl_vars['j']->iteration == 1;$_smarty_tpl->tpl_vars['j']->last = $_smarty_tpl->tpl_vars['j']->iteration == $_smarty_tpl->tpl_vars['j']->total;?>
 							<?php if ($_smarty_tpl->tpl_vars['i']->value*3+$_smarty_tpl->tpl_vars['j']->value<count($_smarty_tpl->tpl_vars['pic_result']->value)){?>
								<td>
									<a href="/rjyohh/pa4/search?q=<?php echo $_smarty_tpl->tpl_vars['caption']->value[$_smarty_tpl->tpl_vars['i']->value*3+$_smarty_tpl->tpl_vars['j']->value];?>
">
										<img src = "<?php echo $_smarty_tpl->tpl_vars['pic_result']->value[$_smarty_tpl->tpl_vars['i']->value*3+$_smarty_tpl->tpl_vars['j']->value]['url'];?>
" width="200" height="200">
									</a>
									<br>                    
										Caption: <?php echo $_smarty_tpl->tpl_vars['caption']->value[$_smarty_tpl->tpl_vars['i']->value*3+$_smarty_tpl->tpl_vars['j']->value];?>

									<br>                    
										Created on: <?php echo $_smarty_tpl->tpl_vars['pic_result']->value[$_smarty_tpl->tpl_vars['i']->value*3+$_smarty_tpl->tpl_vars['j']->value]['date'];?>

									<br>
										Sim Score: <?php echo $_smarty_tpl->tpl_vars['pic_result']->value[$_smarty_tpl->tpl_vars['i']->value*3+$_smarty_tpl->tpl_vars['j']->value]['score'];?>

									</td>                   
							<?php }?>                   
						<?php }} ?>              
					</tr>       
 				<?php }} ?>          
			</table>  
		<?php }?>
		<form name="input"  method="GET">
			<input type="text" name="q">
			<input type="submit" value="Search">
		</form>
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