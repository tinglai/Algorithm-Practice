#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid){
		if(obstacleGrid.empty()) return 0;
		int result = 0;
		int M = (int)obstacleGrid.size();
		int N = (int)obstacleGrid[0].size();
		if(obstacleGrid[M - 1][N - 1] == 1) return 0;
		vector<vector<long>> memo(M, vector<long>(N, -1));
		memo[M - 1][N - 1] = 1;
		result = help(0, 0, obstacleGrid, memo);
		return result;
    }
	long help(int m, int n, vector<vector<int>>& obstacleGrid, vector<vector<long>>& memo){
		if(memo[m][n] != -1) return memo[m][n];
		if(obstacleGrid[m][n] == 1){
			memo[m][n] = 0;
			return 0;
		}
		int M = (int)obstacleGrid.size();
		int N = (int)obstacleGrid[0].size();

		if(m < M - 1 && n < N - 1)
			memo[m][n] = help(m + 1, n, obstacleGrid, memo) + help(m, n + 1, obstacleGrid, memo);
		else if(m == M - 1)
			memo[m][n] = help(m, n + 1, obstacleGrid, memo);
		else if(n == N - 1)
			memo[m][n] = help(m + 1, n, obstacleGrid, memo);
		return memo[m][n];
	}
};

int main(){
	vector<vector<int>> obstacleGrid = {
											{0,0,0},
 											{0,1,0},
											{0,0,0},
											{0,0,0}
										};
	Solution soln;
	int result = soln.uniquePathsWithObstacles(obstacleGrid);
	cout << "result = " << result << endl;
}
