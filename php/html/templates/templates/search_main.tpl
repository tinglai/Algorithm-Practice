{* Smarty *}
{extends 'base.tpl'}
{block name='body'}
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

		{if {$web_result|@count}==0}
			<p><b>NO Search Result!</b></p>
		{else}
			<p>Result show below: </p>
			<p>Number of Search Result: {$web_result|@count}</p>
 			<ul border="1" align="center">
 				{for $i=0 to {$web_result|@count}-1}
					<li border = "1">
						<a color = "b" href = "{$web_result[$i]['url']}">PageID: {$web_result[$i]['id']}       PageTitle: {$web_result[$i]['title']}</a><br>
						{$web_result[$i]['url']} <br>
					</li>
					<div class = "container">
						<div class = "header"><span>Deep Page Summary</span>
						</div>
						<div class = "content">
							<ul>
								<li>
									Category<br>
									<ul>
									{$array_tmp = $category[$i]['cate_array']}
									{foreach from=$array_tmp item = foo}
										<li>{$foo['cate']}</li>
									{/foreach}	
									</ul>
								</li>
								<li>
									Image<br>
									<img src = "{$image_url[$i]['imageUrl']}"></img>
								</li>
								<li>
									InfoBox<br>
									{if {$info_box[$i]['info']}}
										{$info_box[$i]['info']}<br>
									{else}
										No Info Box is Found;<br>
									{/if}
								</li>
							</ul>
						</div>
					</div >
					<br>
 				{/for}          
			</ul>
		{/if}
    </div>
{/block}

