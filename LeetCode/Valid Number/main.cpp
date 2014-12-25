#include <iostream>

using namespace std;

class Solution {
public:
    bool isNumber(const char *s) {
		int i = 0;
		while(true){
			if(s[i] != ' '){
				break;
			}
			i++;
		}
		//ignore the starting spaces

		bool help2Result = help2(s, i);
		if(help2Result == false){
			return false;
		}
		bool help3Result;
		if(s[i] == 'e'){
			i++;
			help3Result = help3(s, i);
			if(help3Result == false){
				return false;
			}
		}

		if(s[i] == ' '){
			i++;
			while(s[i] != '\0'){
				if(s[i] != ' '){
					return false;
					//deal with the tail spaces
				}
				i++;
			}
		}
		return true;
    }

	bool help(char c){
		//this is a function used to check
		//if the char c is 0-9
		if(c == '0' || c == '1' ||
		   c == '2' || c == '3' ||
		   c == '4' || c == '5' || 
		   c == '6' || c == '7' ||
		   c == '8' || c == '9'){
			return true;
		}
		else
			return false;
	}

	bool help2(const char* s, int& i){
		//this is a help function used to check
		//if the string before 'e' is in form of (+-)12345
		bool dot = false;
		bool number = false;
		if(s[i] == '\0'){
			return false;
			//before and after 'e', there has to be something, otherwise it's false
		}
		if(help(s[i]) == true){
			number = true;
		}
		else if(s[i] != '+' && s[i] != '-' && s[i] != '.'){
			return false;
		}
		if(s[i] == '.'){
			dot = true;
		}
		i++;
		//while(s[i] != ' ' || s[i] != '\0' || s[i] != 'e'){
		while(s[i] != '\0' && s[i] != ' ' && s[i] != 'e'){
			if(help(s[i]) == true){
				number = true;
				i++;
				//if current char is numeric
			}
			else if(s[i] == '.' && dot == false){
				dot = true;
				i++;
			}
			else{
				return false;
			}
		}
		return number;
	}

	bool help3(const char* s, int& i){
		//this is a help function used to check
		//if the string after 'e' is in form of (+-)12345
		bool number = false;
		if(s[i] == '\0'){
			return false;
			//before and after 'e', there has to be something, otherwise it's false
		}
		if(help(s[i]) == true){
			number = true;
		}
		else if(s[i] != '+' && s[i] != '-'){
			return false;
		}
		i++;
		while(s[i] != ' ' && s[i] != '\0'){
			if(help(s[i]) == true){
				number = true;
				i++;
				//if current char is numeric
			}
			else{
				return false;
			}
		}
		return number;
	}

};

int main(){
	char s[] = "1131.";
	cout << "s = ";
	cin >> s;
	Solution soln;
	if(soln.isNumber(s)){
		cout << "this string is numeric" << endl;
	}
	else{
		cout << "this string is not numeric" << endl;
	}
}



/*
#include <iostream>

using namespace std;

class Solution {
public:
    bool isNumber(const char *s) {
		int i = 0;
		while(true){
			if(s[i] != ' '){
				break;
			}
			i++;
		}
		//ignore the starting spaces
		int j = i;//j is used to keep track of the first char of the string(non-space)

		bool dot = false;//used to check if dot has shown
		bool expo = false;//used to check if e has shown
		bool neg = false;//used to check if '-' sign has shown
		bool pos = false;//used to check if '+' sign has shown
		bool number = false;
		
		if(s[i] == '\0') return false;
		while(true){
			if(help(s[i])){
				i++;
				number = true;
			}
			else{
				if(s[i] == 'e' && expo == false){
					if(i == j){
						return false;
						//'e' cannot be the first char in the string
					}
					expo = true;
					i++;
					if(help(s[i]) == false && s[i] != '-' && s[i] != '+'){
						return false;
					}
					//'e' has to be followed with a number
				}
				else if(s[i] == '.' && dot == false){
					dot = true;
					i++;
					if(expo == true) return false;
					if(s[i] == 'e'){
						if(help(s[i-2]) == false){
							return false;
						}
					}
					else if(s[i] != '\0' && s[i] != ' ' && help(s[i]) == false){
						return false;
					}
				}
				else if(s[i] == '-' && neg == false){
					if(i != j && s[i - 1] != 'e'){
						return false;
						//'-' has to be the first char in the string
						//or it has to be after 'e'
					}
					neg = true;
					i++;
					if(help(s[i]) == false && s[i] != '.'){
						return false;
					}
					//'-' has to be followed with a number
				}
				else if(s[i] == '+' && pos == false){
					if(i != j && s[i - 1] != 'e'){
						return false;
						//'+' has to be the first char in the string
						//or it has to be after 'e'
					}
					pos = true;
					i++;
					if(help(s[i]) == false && s[i] != '.'){
						return false;
					}
					//'+' has to be followed with a number or '.'
				}
				else{
					return false;
				}

			}

			if(s[i] == '\0' || s[i] == ' '){
				break;
			}
		}//while

		if(s[i] == ' '){
			i++;
			while(s[i] != '\0'){
				if(s[i] != ' '){
					return false;
					//deal with the tail spaces
				}
				i++;
			}
		}
		return number;
    }

	bool help(char c){
		//this is a function used to check
		//if the char c is 0-9
		if(c == '0' || c == '1' ||
		   c == '2' || c == '3' ||
		   c == '4' || c == '5' || 
		   c == '6' || c == '7' ||
		   c == '8' || c == '9'){
			return true;
		}
		else
			return false;
	}
};

int main(){
	char s[] = "1131.";
	cout << "s = ";
	cin >> s;
	Solution soln;
	if(soln.isNumber(s)){
		cout << "this string is numeric" << endl;
	}
	else{
		cout << "this string is not numeric" << endl;
	}
}
*/
