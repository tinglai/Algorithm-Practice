{* Smarty *}
{extends 'base.tpl'}
{block name='body'}
    <h1 style="font-family: Impact">Register Page</h1>
    <div>
		{if isset($displayMsg)}
			<p>{$displayMsg}</p><br>
		{/if}
		<form action ="/rjyohh/pa4/user" method = "post">
			Username(*): <input type = "text" name = "username" required 
			   pattern ={literal}"[A-Za-z0-9_]{3,}"{/literal} 
			   title = "At least 3 character long & only letter, digit and underscore allowed"><br>
			First name: <input type = "text" name = "firstname" ><br>
			Last name: <input type = "text" name = "lastname"><br>
			E-mail address(*): <input type = "email" name = "email" required><br>
		   	Password(*): <input type = "password" id = "pwd" name = "pwd" required 
				   pattern ={literal}"(?=(.*[0-9]+))(?=(.*[A-Za-z]+))[0-9A-Za-z_]{5,15}"{/literal}
	   
			   title = "5-15 characters long & only letter, digit and underscore allowed. At least one character and one digit"><br>
			Password verification(*): <input type = "password" id = "pwdv" name = "pwdv" required 
				   pattern ={literal}"(?=(.*[0-9]+))(?=(.*[A-Za-z]+))[0-9A-Za-z_]{5,15}"{/literal}
			   title = "5-15 characters long & only letter, digit and underscore allowed. At least one character and one digit"><br>

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

			<input type = "submit" name = "submit" value = "Submit">
		</form>

		<p><a href = "/rjyohh/pa4/login">Login Now!</a></p>
    </div>
{/block}

