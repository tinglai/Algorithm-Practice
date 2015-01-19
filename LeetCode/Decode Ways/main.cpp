#include <iostream>

using namespace std;

class Solution{
public:
    int numDecodings(string s){
		if(s.empty()) return 0;
		if(s.size() == 1){
			if(s[0] != '0') return 1;
			else return 0;
		}
		string newS;
		for(unsigned int i = 0; i < s.size(); i++){
			if(s[i] != '0'){
				newS.push_back(s[i]);
			}
		}
		int result = 0;
		int last = 1;
		int lastlast = 1;
		for(unsigned int i = 1; i < newS.size(); i++){
			if(newS[i - 1] == '1'){
				result = last + lastlast;
				lastlast = last;
				last = result;
			}
			else if(newS[i - 1] == '2'){
				if((int)(newS[i] - '0') <=	6){
					result = last + lastlast;
					lastlast = last;
					last = result;
				}
				else{
					lastlast = last;
					result = last;
				}
			}
			else{
				lastlast = last;
				result = last;
			}
		}
		return result;
    }
};

int main(){
	string s;
	cout << "s = ";
	cin >> s;
	Solution soln;
	int result = soln.numDecodings(s);
	cout << "result = " << result << endl;
}
