#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    int uniquePaths(int m, int n){
		int result = 0;
		if(m <= 0 || n <= 0) return result;
		vector<vector<long>> memo(m, vector<long>(n, -1));
		result = (int)help(m, n, memo);
		return result;
    }
	long help(int m, int n, vector<vector<long>>& memo){
		if(m == 1 || n == 1) return 1;
		if(memo[m - 1][n - 1] != -1) return memo[m - 1][n - 1];
		memo[m - 1][n - 1] = help(m - 1, n, memo) + help(m, n - 1, memo);
		return memo[m - 1][n - 1];
	}
};

int main(){
	int m, n;
	cout << "m = "; cin >> m;
	cout << "n = "; cin >> n;
	Solution soln;
	int result = soln.uniquePaths(m, n);
	cout << "result = " << result << endl;
}
