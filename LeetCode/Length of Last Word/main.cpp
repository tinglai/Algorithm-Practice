#include <iostream>

using namespace std;

class Solution{
public:
    int lengthOfLastWord(const char *s){
		if(s[0] == '\0') return 0;
		int itr = 0;
		int startLast = 0;
		int endLast = 0;
		while(s[itr] != '\0'){
			if(s[itr] != ' '){
				endLast = itr;
			}
			itr++;
		}
		startLast = endLast;
		while(startLast >= 0){
			if(s[startLast] == ' '){
				break;
			}
			startLast--;
		}
		return endLast - startLast;
    }
};

int main(){
	char *s = "";
	//char *s = "  asdkl ds dfa   ";
	Solution soln;
	int result = soln.lengthOfLastWord(s);
	cout << "result = " << result << endl;
}
