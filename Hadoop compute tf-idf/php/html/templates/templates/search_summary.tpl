{* Smarty *}
{extends 'base.tpl'}
{block name='body'}
    <h1 style="font-family: Impact">Summary</h1>
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

		{if {$pic_result|@count}==0}
			<p><b>NO Search Result!</b></p>
		{else}
			<p>BY CLICK THE PIC, FIND THE SIMILAR PIC!</p>
			<p>Number of Search Result: {$pic_result|@count}</p>
 			<table border="1" align="center">
 				{for $i=0 to ceil(({$pic_result|@count})/3) - 1}
					<tr>
						{for $j=0 to 2}
 							{if $i*3+$j < $pic_result|@count}
								<td>
									<a href="/rjyohh/pa6/search?q={$caption[$i * 3 + $j]}">
										<img src = "{$pic_result[$i * 3 + $j]['url']}" width="200" height="200">
									</a>
									<br>                    
										Caption: {$caption[$i * 3 + $j]}
									<br>                    
										Created on: {$pic_result[$i * 3 + $j]['date']}
									<br>
										Sim Score: {$pic_result[$i * 3 + $j]['score']}
									</td>                   
							{/if}                   
						{/for}              
					</tr>       
 				{/for}          
				<tr>
					<form name="detail" method="POST" action = "/rjyohh/pa6/search/summary">
						<input type="submit" value="show summary">
					</form>
				<tr>
			</table>  
		{/if}
    </div>
{/block}

