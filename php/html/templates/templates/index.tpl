{* Smarty *}
{extends 'base.tpl'}
{block name='body'}
	<h1 style="font-family: Impact">User based Album System</h1>
	<div>
    	<p style="font-size:20px; font-family: Impact">website brief introduction</p><br>
	<a style="font-size:20px; font-family: Impact" href = "/rjyohh/pa6/search">Search Page For Project6</a><br>
	</div>
	<div>
    	<h4 style="font-family: Arial">{$headMsg}</h4>
		<table border = "1px">
			<thead>
				<tr>
					<th colspan= "3">All Ablums You Can See</th>
				</tr>
				<tr>
					<th>Album Name</th>
					<th>Owner</th>
					<th>Access</th>
				</tr>
			</thead>
			<tbody>

			{if isset($smarty.session.name)}
          	{foreach from=$album_to_logged key= key item=value}
             	<tr>
					<td><a href= "/rjyohh/pa6/album?id={$key}">{$value.title}</a></td>
					<td>{$value.username}</td>
					<td>{$value.access}</td>
				</tr>
          	{foreachelse}
	  		{/foreach}

			{else}
          	{foreach from=$album_to_unlogged key= key item=value}
             	<tr>
					<td><a href= "/rjyohh/pa6/album?id={$key}">{$value.title}</a></td>
					<td>{$value.username}</td>
					<td>{$value.access}</td>
				</tr>
          	{foreachelse}
	  		{/foreach}
			{/if}	
			</tbody>
      	</table>
		<p>
			{if !isset($smarty.session.name)}
				<a href = "/rjyohh/pa6/login">Log In</a><br>
			{/if}
			<a href = "/rjyohh/pa6/user">Register and Join</a><br>
		</p>
	</div>
{/block}
