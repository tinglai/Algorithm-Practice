<?php /* Smarty version Smarty-3.1.14, created on 2014-12-06 16:59:19
         compiled from "/var/www/html/group71/admin/pa6/php/html/templates/templates/search_main.tpl" */ ?>
<?php /*%%SmartyHeaderCode:15781540215482a46e961bb8-98437310%%*/if(!defined('SMARTY_DIR')) exit('no direct access allowed');
$_valid = $_smarty_tpl->decodeProperties(array (
  'file_dependency' => 
  array (
    '2c1ef488d22ab9a430eac8350f18eee6ce904427' => 
    array (
      0 => '/var/www/html/group71/admin/pa6/php/html/templates/templates/search_main.tpl',
      1 => 1417903157,
      2 => 'file',
    ),
    '4f19271ef9d176b7919b6d8a9e0b9d25b13d66e0' => 
    array (
      0 => '/var/www/html/group71/admin/pa6/php/html/templates/templates/base.tpl',
      1 => 1417900707,
      2 => 'file',
    ),
  ),
  'nocache_hash' => '15781540215482a46e961bb8-98437310',
  'function' => 
  array (
  ),
  'version' => 'Smarty-3.1.14',
  'unifunc' => 'content_5482a46e9e7487_73956182',
  'variables' => 
  array (
    'title' => 0,
  ),
  'has_nocache_code' => false,
),false); /*/%%SmartyHeaderCode%%*/?>
<?php if ($_valid && !is_callable('content_5482a46e9e7487_73956182')) {function content_5482a46e9e7487_73956182($_smarty_tpl) {?>
<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01//EN">
<html lang="en">
<head>

    <link rel="stylesheet" href="/static/css/style.css" />

	<script src = "//code.jquery.com/jquery-1.10.2.js"></script>
	<script src = "//code.jquery.com/ui/1.11.2/jquery-ui.js"></script>

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
		<script type = "text/javascript">
			function getValue(val){
				document.getElementById("weight").innerHTML = val;
			}
		</script>
		<form name="input"  method="POST" action = "/rjyohh/pa6/search">
			<input type="text" name="q"><br>
			<span> w = </span>
			<span id = "weight">0.80</span>
			<input type="range" name="w" id = "weight" value=0.80 min="0.00" max="1.00" step = 0.01 onchange="getValue(this.value)">
			<input type="submit" value="Search">
		</form>

		<?php ob_start();?><?php echo count($_smarty_tpl->tpl_vars['web_result']->value);?>
<?php $_tmp1=ob_get_clean();?><?php if ($_tmp1==0){?>
			<p><b>NO Search Result!</b></p>
		<?php }else{ ?>
			<p>Result show below: </p>
			<p>Number of Search Result: <?php echo count($_smarty_tpl->tpl_vars['web_result']->value);?>
</p>
 			<ul border="1" align="center">
 				<?php ob_start();?><?php echo count($_smarty_tpl->tpl_vars['web_result']->value);?>
<?php $_tmp2=ob_get_clean();?><?php $_smarty_tpl->tpl_vars['i'] = new Smarty_Variable;$_smarty_tpl->tpl_vars['i']->step = 1;$_smarty_tpl->tpl_vars['i']->total = (int)ceil(($_smarty_tpl->tpl_vars['i']->step > 0 ? $_tmp2-1+1 - (0) : 0-($_tmp2-1)+1)/abs($_smarty_tpl->tpl_vars['i']->step));
if ($_smarty_tpl->tpl_vars['i']->total > 0){
for ($_smarty_tpl->tpl_vars['i']->value = 0, $_smarty_tpl->tpl_vars['i']->iteration = 1;$_smarty_tpl->tpl_vars['i']->iteration <= $_smarty_tpl->tpl_vars['i']->total;$_smarty_tpl->tpl_vars['i']->value += $_smarty_tpl->tpl_vars['i']->step, $_smarty_tpl->tpl_vars['i']->iteration++){
$_smarty_tpl->tpl_vars['i']->first = $_smarty_tpl->tpl_vars['i']->iteration == 1;$_smarty_tpl->tpl_vars['i']->last = $_smarty_tpl->tpl_vars['i']->iteration == $_smarty_tpl->tpl_vars['i']->total;?>
					<li border = "1">
						<a color = "b" href = "<?php echo $_smarty_tpl->tpl_vars['web_result']->value[$_smarty_tpl->tpl_vars['i']->value]['url'];?>
">PageID: <?php echo $_smarty_tpl->tpl_vars['web_result']->value[$_smarty_tpl->tpl_vars['i']->value]['id'];?>
       PageTitle: <?php echo $_smarty_tpl->tpl_vars['web_result']->value[$_smarty_tpl->tpl_vars['i']->value]['title'];?>
</a><br>
						<?php echo $_smarty_tpl->tpl_vars['web_result']->value[$_smarty_tpl->tpl_vars['i']->value]['url'];?>
 <br>
					</li>
					<div class = "container">
						<div class = "header"><span>Deep Page Summary</span>
						</div>
						<div class = "content">
							<ul>
								<li>
									Category<br>
									<ul>
									<?php $_smarty_tpl->tpl_vars['array_tmp'] = new Smarty_variable($_smarty_tpl->tpl_vars['category']->value[$_smarty_tpl->tpl_vars['i']->value]['cate_array'], null, 0);?>
									<?php  $_smarty_tpl->tpl_vars['foo'] = new Smarty_Variable; $_smarty_tpl->tpl_vars['foo']->_loop = false;
 $_from = $_smarty_tpl->tpl_vars['array_tmp']->value; if (!is_array($_from) && !is_object($_from)) { settype($_from, 'array');}
foreach ($_from as $_smarty_tpl->tpl_vars['foo']->key => $_smarty_tpl->tpl_vars['foo']->value){
$_smarty_tpl->tpl_vars['foo']->_loop = true;
?>
										<li><?php echo $_smarty_tpl->tpl_vars['foo']->value['cate'];?>
</li>
									<?php } ?>	
									</ul>
								</li>
								<li>
									Image<br>
									<img src = "<?php echo $_smarty_tpl->tpl_vars['image_url']->value[$_smarty_tpl->tpl_vars['i']->value]['imageUrl'];?>
"></img>
								</li>
								<li>
									InfoBox<br>
									<?php ob_start();?><?php echo $_smarty_tpl->tpl_vars['info_box']->value[$_smarty_tpl->tpl_vars['i']->value]['info'];?>
<?php $_tmp3=ob_get_clean();?><?php if ($_tmp3){?>
										<?php echo $_smarty_tpl->tpl_vars['info_box']->value[$_smarty_tpl->tpl_vars['i']->value]['info'];?>
<br>
									<?php }else{ ?>
										No Info Box is Found;<br>
									<?php }?>
								</li>
							</ul>
						</div>
					</div >
					<br>
 				<?php }} ?>          
			</ul>
		<?php }?>
    </div>

		</div>
	</div>
	<script type="text/javascript" src="/static/js/main.js"></script>
	<script type="text/javascript" src="/static/js/click.js"></script>
</body>
<footer class = "center">
	<p align = "center">Posted by: Jiawei and Ting</p>
	<p align = "center">Contact information:<br><a href="mailto:wangjiaw@umich.edu">wangjiaw@umich.edu</a>
	<br><a href="mailto:laiting@umich.edu">laiting@umich.edu</a><br></p>
</footer>
</html>
<?php }} ?>