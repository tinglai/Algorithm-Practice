#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    int numTrees(int n){
		if(n <= 0) return 0;
		vector<int> memo(n + 1, -1);
		// memo[i1] is the number of unique BSTs
		// when n = i
		return help(n, memo);
    }
	int help(int n, vector<int>& memo){
		if(memo[n] != -1){
			return memo[n];
		}
		if(n <= 1){
			memo[n] = 1;
			return 1;
		}
		int result = 0;
		for(int i = 1; i <= n; i++){
			int left = help(i - 1, memo);
			int right = help(n - i, memo);
			result += left * right;
		}
		memo[n] = result;
		return result;
	}
};

int main(){
	Solution soln;
	int n;
	cout << "n = ";
	cin >> n;
	int result = soln.numTrees(n);
	cout << "result = " << result << endl;
}
