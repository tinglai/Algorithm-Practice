{* Smarty *}
{extends 'base.tpl'}
{block name='body'}
{if $album_title != NULL}
	<h1 align="center">{$album_title}</h1>
	<h2 align="center">Owner: {$album_username}</h2>
	{if $state==0}
		{if isset($displayMsg)}
			<p>{$displayMsg}</p>
		{/if}
		<p class="important">
		    <table border="1" align="center">
				<tr>
					<td colspan=3 align = 'center'>
<!--album title-->
					<form action="/rjyohh/pa4/album/edit?id={$albumid}" method="POST">
						Chage Album Name :<input type = "text", name = "newTitle">
						<input type = "submit" value = "Change">
						<input type="hidden" name='op' value="changeName">
						<input type="hidden" name='albumid' value="{$albumid}">
					</form>
					</td>
				</tr>
				<tr>
<!--permission-->
					<td colspan=3 align = 'center'>
					<form action="/rjyohh/pa4/album/edit?id={$albumid}" method="POST">
						Chage Album's Permission:
						<input type = "radio", name = "permission" value = 'public'> public
						<input type = "radio" name = "permission" value = 'private'> private
						<input type = "submit" value = 'Change'>
						<input type="hidden" name='op' value="changePermission">
						<input type="hidden" name='album_username' value="{$album_username}">
						<input type="hidden" name='albumid' value="{$albumid}">
					</form>
					</td>
				</tr>

				{for $i=0 to ceil(({$pic_in_album|@count})/3) - 1}
<!--delete-->
				<tr>
					{for $j=0 to 2}
						{if $i*3+$j < $pic_in_album|@count}
						<td>
							<a href="/rjyohh/pa4/pic?id={$pic_in_album[$i * 3 + $j]['picid']}">
							<img src = "{$pic_in_album[$i * 3 + $j]['url']}" width="200" height="200">
							</a>
							<br>
							Caption: {$caption[$i * 3 + $j]}
							<br>
							Created on: {$pic_in_album[$i * 3 + $j]['date']}
							<br>
							<form action="/rjyohh/pa4/album/edit?id={$albumid}" method="POST">
								<input type="hidden" name='op' value="delete">
								<input type="hidden" name='albumid' value="{$albumid}">
								<input type="hidden" name='picid' value="{$pic_in_album[$i * 3 + $j]['picid']}">
								<input type="submit" value="Delete">
							</form>
						</td>
						{/if}
					{/for}
				</tr>
				{/for}
				<tr>
					<td colspan=3 align="center">Upload:</td>
				</tr>
				<tr>
<!--add-->
					<td colspan=3 align="center">
						<form enctype="multipart/form-data" action="/rjyohh/pa4/album/edit?id={$albumid}" method="POST">
							<input type="hidden" name="MAX_FILE_SIZE" value="300000000">
							<input type="file" name="newfile">
							<input type="hidden" name="op" value="add">
							<input type="hidden" name="albumid" value={$albumid}>
							<input type="submit" value="Submit">
						</form>
					</td>
				</tr>

<!--give access-->
				{if $album_access=='private'}


                    <tr>
                        <td colspan=3 align='left'>
						Give Access to:<br>
                        </td>
                    </tr>
 					{for $i=0 to ceil(({$user|@count})/3) - 1}
                    <tr>
					<form action="/rjyohh/pa4/album/edit?id={$albumid}" method="POST">
                    {for $j=0 to 2}
                        {if $i*3+$j < $user|@count} 
                        <td>
							<input type = "checkbox", value='{$user[$i*3+$j]}' name = "user[]"> {$user[$i*3+$j]}
                        </td>
                        {/if}
                    {/for}
                    </tr>
					{/for}
					<tr>
						<input type="hidden" name='op' value="giveAccess">
						<input type="hidden" name='albumid' value="{$albumid}">
						<input type="hidden" name='album_username' value="{$album_username}">
					<td>
						<input type = "submit" value = "Submit">
					</td>
					</form>
					</tr>
				{/if}
				<tr>
					<td colspam=3 align="center">
						<a href="/rjyohh/pa4/albums/edit?username={$album_username}">Back To My Albums</a>
					</td>
				</tr>
			</table>
		</p>
	{else}
		<p>{$displayMsg}</p>
	{/if}
{else}
<h1>Could not find ALBUM with albumid {$albumid}</h1>
{/if}
{/block}
