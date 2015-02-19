#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    int climbStairs(int n){
		if(n == 0) return 1;
		vector<long> memo(n, -1);
		memo[0] = 1;
		memo[1] = 2;
		return (int)help(n, memo);
    }
	long help(int n, vector<long>& memo){
		if(memo[n - 1] != -1) return memo[n - 1];
		memo[n - 1] = help(n - 1, memo) + help(n - 2, memo);
		return memo[n - 1];
	}
};

int main(){
	int n;
	cout << "n = "; cin >> n;
	Solution soln;
	int result = soln.climbStairs(n);
	cout << "result = " << result << endl;
}
