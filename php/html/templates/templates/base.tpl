{* Smarty *}
<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01//EN">
<html lang="en">
<head>

    <link rel="stylesheet" href="/static/css/style.css" />

	<script src = "//code.jquery.com/jquery-1.10.2.js"></script>
	<script src = "//code.jquery.com/ui/1.11.2/jquery-ui.js"></script>

    <title>{$title}</title>

</head>
<body class = "center">
	<div id= "container">

	{if isset($smarty.session.name)}
		<div id ="header" >
			<ul id= "navi">
				<li><a href = "/rjyohh/pa4/">Home</a></li>
				<li><a href = "/rjyohh/pa4/user/edit?username={$smarty.session.name}">Edit Account</a></li>
				<li><a href = "/rjyohh/pa4/albums/edit?username={$smarty.session.name}">My Albums</a></li>
				<li><a href = "/rjyohh/pa4/logout">Logout</a></li>
			</ul>
		</div>
		logged in as {$smarty.session.name}
	{/if}
		<div id="main">
    		{block "body"}Default Body Text{/block}
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
