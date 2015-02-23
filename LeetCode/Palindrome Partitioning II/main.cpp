#include <iostream>
#include <vector>
#include <string>
#include <climits>

using namespace std;

class Solution{
public:
    int minCut(string s){
		int size = (int)s.size();
		if(size <= 1) return 0;
		vector<int> memo(s.size() + 1);
		for(unsigned int i = 0; i < memo.size(); i++){
			memo[i] = i - 1;
		}
		for(int i = 0; i < (int)s.size(); i++){
			for(int j = 0; 
			   (i - j) >= 0 
			   	      && i + j < (int)s.size() 
 			          && s[i - j] == s[i + j]; 
			   j++){
				memo[i + j + 1] = min(memo[i - j] + 1, memo[i + j + 1]);
			}
			for(int j = 0; i - j >= 0 && i + j + 1 < (int)s.size() && s[i - j] == s[i + j + 1]; j++){
				memo[i + j + 2] = min(memo[i - j] + 1, memo[i + j + 2]);
			}
		}
		return memo.back();
    }
}; 

int main(){
	string s = "aab";
	Solution soln;
	int result = soln.minCut(s);
	cout << "result = " << result << endl;
}
