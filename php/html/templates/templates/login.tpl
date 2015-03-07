{* Smarty *}
{extends 'base.tpl'}
{block name='body'}
    <h1 style="font-family: Impact">Login Here</h1>
	{if isset($login_displayMsg)}
	<b>{$login_displayMsg}</b>
	{/if}
    <div>
		<!--<form action ="/rjyohh/pa4/login?prevUrl={$prevUrl}" method = "post">-->
		<form action ="/rjyohh/pa4/login" method = "POST">
			Username: <input type = "text" name = "username"><br>
			Password: <input type = "password" name = "pwd"><br>
			<input type = "hidden" value = {$prevUrl} name = "prevUrl">
			<input type = "submit" value = "Log in" name = "submit">
		</form>
		<p><a href = "/rjyohh/pa4/user">New User? Register Here!</a></p>
		<p><a href = "/rjyohh/pa4/">Just want to look around.</a></p>
    </div>
{/block}

