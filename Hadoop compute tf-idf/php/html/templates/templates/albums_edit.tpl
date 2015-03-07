{* Smarty *}
{extends 'base.tpl'}
{block name='body'}
{if $title_access_list|@count != 0}
<h1 align="center">ALBUMS of {$username}</h1>
{else}
<h1>You have no private albums yet</h1>
{/if}

<p class="important">
        <table border="1px" align='center'>
                <thead>
                        <tr>
                                <th>Album Name</th>
                                <th>Access</th>
                                <th>Edit</th>
                                <th>Delete</th>
                        </tr>
                </thead>
                <tbody>
                {foreach from=$title_access_list key=key item = value}
                        <tr>
                                <td><a href= "/rjyohh/pa4/album?id={$key}">{$value.title}</a></td>
                                <td align="center">{$value.access}</td>
                                <td><a href= "/rjyohh/pa4/album/edit?id={$key}">EDIT</a></td>
				<td>
					<form method="POST" action="/rjyohh/pa4/albums/edit?username={$username}">
						<input type="submit" value="DELETE">
						<input type="hidden" name="op" value="delete">
						<input type="hidden" name="albumid" value={$key}>
					</form>
				</td>
                        </tr>
                {foreachelse}
                {/foreach}
                        <tr>
				<td>NEW:__________</td>
				<td>
					<form method="POST" action="/rjyohh/pa4/albums/edit?username={$username}">
						New Album Name: <input type="text" name="title"><br>
						<input type="radio" name="permission" value = "public"> publica<br>
						<input type="radio" name="permission" value = "private"> private<br>
						<input type="hidden" name="op" value="add">
						<input type="hidden" name="username" value="{$username}">
						<input type="submit" value = "ADD">
					</form>
				</td>
                        </tr>
                </tbody>
    </table>
        <a href = "/rjyohh/pa4/" align='center'>Home Page</a>
</p>
{/block}
