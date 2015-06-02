#include <iostream>
#include <cmath>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution{
public:
    int minimumTotal(vector<vector<int> > &triangle){
		if(triangle.empty()) return 0;
		unordered_map<int, int> memo;
		int result;
	//	help(0, 0, triangle, memo, result);
		result = help2(triangle);
		return result;
    }
	void help(int row, int coln, vector<vector<int>>& triangle, unordered_map<int, int>& memo, int& result){
	// the root of the triangle this help func is traversing is at
	// triangle[row][coln]
		int idx = row * ((triangle.back()).size()) + coln;
		if(memo.count(idx)){
			result = memo[idx];
			return;
		}
		if(row == triangle.size() - 1){
			result = triangle[row][coln];
			memo[idx] = result;
			return;
		}
		int left = 0, right = 0;
		help(row + 1, coln, triangle, memo, left);
		help(row + 1, coln + 1, triangle, memo, right);
		result = triangle[row][coln] + min(left, right);
		memo[idx] = result;
	}
	int help2(vector<vector<int>>& triangle){
	// method 2
		vector<int> memo(triangle.back());
		for(int i = triangle.size() - 2; i >= 0; i--){
			for(unsigned int j = 0; j < triangle[i].size(); j++){
				memo[j] = min(memo[j], memo[j + 1]) + triangle[i][j];
			}
		}
		return memo[0];
	}
};

int main(){
	vector<vector<int>> triangle = {};
/*
	vector<vector<int>> triangle = {
										     {2},
										    {3,4},
										   {6,5,7},
										  {4,1,8,3}
									};
*/
	Solution soln;
	int result = soln.minimumTotal(triangle);
	cout << "result = " << result << endl;
}
