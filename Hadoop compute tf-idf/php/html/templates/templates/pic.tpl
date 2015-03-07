{* Smarty *}
{extends 'base.tpl'}
{block name='body'}
<p class="important", align="left">
<h1 align = "center">PIC {$picid}</h1></td>
{if $pic_url}
	{if $state==0}
		<br>
<!--so all the relative url starts from the website root directory,
which in this case is var/www/html/group/admin/pa4/php/html-->
		<br>
			<table style="margin-top:10px; margin-left:10px;">
			<tr>
				<td></td>
				<td align="center">
					{if $next_picid != NULL}
						Click photo to the next page of this album
					{else}
						Last page of this album
					{/if}
				</td>
				<td></td>
			</tr>

			<tr>
				<td></td>
				{if $next_picid != NULL}
					<td align="center"><a href="/rjyohh/pa4/pic?id={$next_picid}"><img src="{$pic_url}"></a><br>
					Caption: {$caption}
					</td>
				{else}
					<td align="center"><img src="{$pic_url}"><br>
					Caption: {$caption}
					</td>
				{/if}
				<td></td>
			</tr>

			<tr>
				<td>
					{if $prev_picid != NULL}
						<a href="/rjyohh/pa4/pic?id={$prev_picid}">PREV</a>
					{else}
					First Pic
					{/if}
				</td>
				<td align="center">
					<a href="/rjyohh/pa4/album?id={$albumid}">Back To Album</a>
				</td>
				<td>
					{if $next_picid != NULL}
						<a href="/rjyohh/pa4/pic?id={$next_picid}">NEXT</a>
					{else}
						Last Pic
					{/if}
				</td>
			</tr>
			</table>
	{else}
		<p align='center'>
			{$displayMsg}<br>
			<a href="/rjyohh/pa4/login">Login Here</a>&nbsp;&nbsp;&nbsp;
			<a href="/rjyohh/pa4/">Back To Home Page</a>
		</p>
	{/if}
{else}
<h1>PIC {$picid} Not Found</h1>
{/if}
</p>
{/block}
