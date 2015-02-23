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
		if(isPalindrome(s)) return 0;
		vector<int> memo(size + 1);
		memo[0] = 0;
		memo[1] = 0;
		for(int i = 1; i < size; i++){
			
		}
		return memo.back();
    }
	bool isPalindrome(string s){
		int size = (int)s.size();
		if(size <= 1) return true;
		int i = 0; 
		int j = size - 1;
		while(i < j){
			if(s[i] != s[j]) return false;
			i++;
			j--;
		}
		return true;
	}
	void help(vector<int>& memo, int idx, string& s){
		for(int i = idx; i >= 0; i--){
			string tempStr = s.substr(i, idx - i + 1);
			int tempCut = 1 + memo[idx] + help(memo, , tempStr);
		}
	}
}; 



int main(){
	string s = "aab";
	Solution soln;
	int result = soln.minCut(s);
	cout << "result = " << result << endl;
}
