#include <iostream>

using namespace std;

class Solution {
public:
    bool isMatch(const char *s, const char *p) {
		int i = 0;
		int j = 0;
		return(help(s, p, i, j));
    }
	bool help(const char *s, const char *p, int i, int j){
//help function returns if substring of s starting from i
//matches the pattern forming from substring of p starting from j
//this can be improved using DP
		if(s[i] == '\0' && p[j] == '\0'){
			return true;
		}
		
		if(p[j] == '\0') return false;

		if(p[j] == '.'){
			if(p[j + 1] == '*'){
				//'*' can be zero or more preceding element
				do{
					if(help(s, p, i, j + 2)){
						return true;
					}
					i++;
				}while(s[i - 1] != '\0');
				return false;
			}
			else{
				if(s[i] == '\0') return false;
				return help(s, p, i + 1, j + 1);
			}
		}

		else{
			if(p[j + 1] == '*'){
				do{
					if(help(s, p, i, j + 2)){
						return true;
					}
					i++;
				}while(s[i - 1] == p[j]);
				return false;
			}
			else{
				if(s[i] == p[j]){
					return help(s, p, i + 1, j + 1);
				}
				else{
					return false;
				}
			}
		}
	}
};

int main(){
	char s[] = "b";
	char p[] = "";

	Solution soln;
	if(soln.isMatch(s, p)){
		cout << "matched" << endl;
	}
	else{
		cout << "not matched" << endl;
	}
}
