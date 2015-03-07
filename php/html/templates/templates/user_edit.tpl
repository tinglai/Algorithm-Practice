{* Smarty *}
{extends 'base.tpl'}
{block name='body'}
<h1 style="font-family: Impact">Edit Your Account</h1>
******here you can edit your account******
	<div>
		{if isset($displayMsg)}
			<p><b>{$displayMsg}</b></p><br>
		{/if}
	<table>
	<tr>
		<form action="/rjyohh/pa4/user/edit?username={$username}" method="POST">
			<tr>
				<td>First name: <input type = "text" name = "firstname" value = "{$firstname}"><br></td>
			</tr>
			<tr>
				<td>Last name: <input type = "text" name = "lastname" value = "{$lastname}"><br></td>
			</tr>
			<tr>
				<td>E-mail address: <input type = "email" name = "email" value = "{$email}" required><br></td>
			</tr>
			<!-- Password(*): <input type = "password" id = "pwd" name = "pwd" 
			required pattern ={literal}"[A-Za-z]{1,}[0-9]{1,}[_]"{/literal} 
			-->
			<tr>
				<td>
					Password: <input type = "password" id = "pwd" name = "pwd" value = "{$pwd}"
				   		required pattern ={literal}"(?=(.*[0-9]+))(?=(.*[A-Za-z]+))[0-9A-Za-z_]{5,15}"{/literal}
					    title = "5-15 characters long & only letter, digit and underscore allowed at least one letter and one digit"><br>
				</td>
			</tr>
			<tr>
				<td>
					Password verification(*): <input type = "password" id = "pwdv" name = "pwdv" value = "{$pwdv}"
				   		required pattern ={literal}"(?=(.*[0-9]+))(?=(.*[A-Za-z]+))[0-9A-Za-z_]{5,15}"{/literal}
						title = "5-15 characters long & only letter, digit and underscore allowed at least one letter and one digit"><br>
				</td>
			</tr>

			<!--following JS checks if passwords match-->
			<script type="text/javascript">
				{literal}
				var elem = document.getElementById("pwdv");
				elem.addEventListener("blur", verifyPassword);
				function verifyPassword(){
					if(document.getElementById("pwd").value != document.getElementById("pwdv").value){
						document.getElementById("pwdv").setCustomValidity('The passwords don\'t  match!');
					}
					else{
						document.getElementById("pwdv").setCustomValidity('');
					}
				}
				{/literal}
			</script>
			<tr>
				<td><input type = "hidden" name = "username" value = {$username}></td>
			</tr>
			<tr>
				<td><input type = "submit" name = "submit" value = "SUBMIT"></td>
			</tr>
        </form>
	</tr>
	<tr>
		<td>
			<form action = "/rjyohh/pa4/user/delete?username={$username}" method = "POST">
            	<input type = "hidden" name = "username" value = {$username}>
				<input type = "submit" value = "DELETE">
			</form>
		</td>
	</tr>
	</table>
        <p><a href = "/rjyohh/pa4/login">Login Now!</a></p>
    </div>
{/block}
