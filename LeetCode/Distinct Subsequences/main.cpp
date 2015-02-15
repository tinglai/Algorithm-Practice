#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution{
public:
    int numDistinct(string S, string T){
		if(S == "") return 0;
		if(T == "") return 1;
		vector<vector<int>> memo(S.size(), vector<int>(T.size(), -1));
		(memo.back()).back() = S.back() == T.back() ? 1 : 0;
		int result = help(S, T, 0, 0, memo);
		return result;
    }
// S = "rabbbit", T = "rabbit"
	int help(string& S, string& T, int a, int b, vector<vector<int>>& memo){
		if(b == (int)T.size()){
			return 1;
		}


		if((S.size() - a) < (T.size() - b)){
			return 0;
		}

		if(memo[a][b] != -1) return memo[a][b];
		else if(S.size() - a == T.size() - b){
			memo[a][b] = (S.substr(a) == T.substr(b) ? 1 : 0);
		}
		else if(S[a] != T[b]){
			memo[a][b] = help(S, T, a + 1, b, memo);
		}

		else{
			memo[a][b] = help(S, T, a + 1, b + 1, memo) + help(S, T, a + 1, b, memo);
		}
		return memo[a][b];
	}
};

int main(){
	string S, T;
	S = "ccc";//15
	T = "c";//5
	Solution soln;
	int result = soln.numDistinct(S, T);
	cout << "result = " << result << endl;
}
