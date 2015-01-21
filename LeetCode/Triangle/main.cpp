#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    int minimumTotal(vector<vector<int>> &triangle){
		int result = 0;
		vector<vector<int>> memo;
		for(unsigned int i = 0; i < triangle.size(); i++){
			memo.push_back(vector<int>(triangle[i].size(), -1));
		}
		result = help(triangle, memo, 0, 0);
		return result;
    }
	int help(vector<vector<int>>& triangle, vector<vector<int>>& memo, int a, int b){
		if(memo[a][b] != -1) return memo[a][b];
		if(a == (int)triangle.size() - 1){
			memo[a][b] = triangle[a][b];
		}
		else{
			int left = help(triangle, memo, a + 1, b);
			int right = help(triangle, memo, a + 1, b + 1);
			if(left < right){
				memo[a][b] = left + triangle[a][b];
			}
			else{
				memo[a][b] = right + triangle[a][b];
			}
		}
		return memo[a][b];
	}
};

int main(){
	vector<vector<int>> triangle = {{2}, {3, 4}, {6, 5, 7}, {4, 1, 8, 3}};
	Solution soln;
	int result = soln.minimumTotal(triangle);
	cout << "result = " << result << endl;
}
