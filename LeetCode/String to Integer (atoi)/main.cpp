#include <iostream>
#include <climits>

using namespace std;

class Solution{
public:
    int atoi(const char *str){
		if(str == NULL) return 0; // empty string
		if(str == '\0') return 0;
		int result = 0;
		int sign = 1;
		int i = 0;
		
		i = disturb(str, i);

		while(str[i] == '0'){ // number starting with 0
			i++;
		}
		if(str[i] == '-'){// negative number
			sign = -1; 
			i++;
		}
		if(str[i] == '+'){
			i++;
		}
		i = disturb(str, i);

		while(str[i] == '0'){ // number starting with 0
			i++;
		}

		while(str[i] != '\0'){
			int digit = (int)(str[i] - '0');
			if(result == INT_MAX / 10){ // overflow
				if(sign == 1){
					if(digit > INT_MAX % 10){
						result = digit - INT_MAX % 10;
						sign = -1;
					}
					else result = 10 * result + digit;
				}
				else{
					if(digit > (INT_MAX % 10 + 1)){
						result = digit - INT_MAX % 10 - 1;
						sign = 1;
					}
					else result = 10 * result + digit;
				}
			}
			else{
				result = 10 * result + digit;
			}
			i++;
		}
		result *= sign;
		return result;
    }


	int disturb(const char *str, int i){
		while((str[i] > '9' || str[i] < '0') && str[i] != '+' && str[i] != '-'){ // white spaces
			i++;
		}
		return i;
	}
};


int main(){
	char* str = "1";
	Solution soln;
	int result = soln.atoi(str);
	cout << "result = " << result << endl;
}
