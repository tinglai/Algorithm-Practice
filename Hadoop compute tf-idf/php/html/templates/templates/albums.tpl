{* Smarty *}
{extends 'base.tpl'}
{block name='body'}
{if $title_access_list|@count != 0}
<h1 align="center">ALBUMS of {$username}</h1>
{else}
<h1>You have no private albums yet</h1>
{/if}

<p class="important">
	<table border="1px" width='500' align='center'>
		<thead>
			<tr>
				<th>Album Name</th>
				<th>Owner</th>
				<th>Access</th>
			</tr>
		</thead>
		<tbody>
		{foreach from=$title_access_list key=key item = value}
			<tr>
				<td><a href= "/rjyohh/pa4/album?id={$key}">{$value.title}</a></td>
				<td align="center">{$value.username}</td>
				<td align="center">{$value.access}</td>
			</tr>
		{foreachelse}
		{/foreach}
		</tbody>
    </table> 
	<a href = "/rjyohh/pa4/" align='center'>Home Page</a> 
</p>
{/block}
