{* Smarty *}
{extends 'base.tpl'}
{block name='body'}
{if $album_title != NULL}
	<h1 align="center">{$album_title}</h1>
	<h2 align="center">Owner: {$album_username}</h2>
	{if $state == 0}
		{if isset($displayMsg)}
			<p>{$displayMsg}</p><br>
		{else}
			<p class="important">
			{if {$pic_in_album|@count} == 0}
				<p align = 'center'><b>There are no photos in this album right now.</b></p>
			{else}
			    <table border="1" align="center">
					{for $i=0 to ceil(({$pic_in_album|@count})/3) - 1}
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
							</td>
							{/if}
						{/for}
			        	</tr>
					{/for}
				</table>
			{/if}
				<p align = 'center'>
					{if !isset($smarty.session.name)}
					<a href="/rjyohh/pa4/">Back To All Albums</a>
					{else}
					<a href="/rjyohh/pa4/albums?username={$smarty.session.name}">Back To My Albums</a>
					{/if}
				</p>
			</p>
		{/if}
	{else}
			<p align='center'>{$displayMsg}</p><br>
			<p align='center' ><a href="/rjyohh/pa4/">Back To Home Page</a></p>
	{/if}
{else}
<h1>Could not find ALBUM with albumid {$albumid}</h1>
{/if}
{/block}
