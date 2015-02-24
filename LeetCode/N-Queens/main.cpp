#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution{
public:
    vector<vector<string> > solveNQueens(int n){
		vector<vector<string>> result;
		if(n == 0) return result;
		vector<vector<bool>> memo(n, vector<bool>(n, true));
		// to improve: no need to maintain a n * n memo matrix
		// but just need to update a row vector, a column vector
		// and two diagnol vectors
		vector<vector<int>> resultInt;
		vector<int> tempRes;
		help(resultInt, memo, tempRes, n, 0);
		for(unsigned int i = 0; i < resultInt.size(); i++){
			vector<string> toPush;
			for(unsigned int j = 0; j < resultInt[i].size(); j++){
				string in(n, '.');
				in[resultInt[i][j]] = 'Q';
				toPush.push_back(in);
			}
			result.push_back(toPush);
		}
		return result;
    }
	void help(vector<vector<int>>& result, vector<vector<bool>>& memo,
		      vector<int>& tempRes,int n, int rowIdx){
		if(rowIdx == n){
			vector<int> toPush = tempRes;
			result.push_back(toPush);
			return;
		}

		for(int i = 0; i < n; i++){
			if(!memo[rowIdx][i]) continue;
			tempRes.push_back(i);
			vector<int> update;
			for(int j = rowIdx + 1; j < n; j++){
				if(memo[j][i]){
					update.push_back(j);
					update.push_back(i);
				}
			}
			for(int j = i + 1; j < n && rowIdx + j - i < n; j++){
				if(memo[rowIdx + j - i][j]){
					update.push_back(rowIdx + j - i);
					update.push_back(j);
				}
			}
			for(int j = i - 1; j >= 0 && rowIdx - j + i < n; j--){
				if(memo[rowIdx - j + i][j]){
					update.push_back(rowIdx - j + i);
					update.push_back(j);
				}
			}
			for(unsigned int j = 0; j < update.size(); j += 2){
				memo[update[j]][update[j + 1]] = false;
			}
			help(result, memo, tempRes, n, rowIdx + 1);
			tempRes.pop_back();
			for(unsigned int j = 0; j < update.size(); j += 2){
				memo[update[j]][update[j + 1]] = true;
			}
		}
	}
};

int main(){
	int n = 5;
	Solution soln;
	vector<vector<string>> result = soln.solveNQueens(n);
	for(unsigned int i = 0; i < result.size(); i++){
		for(unsigned int j = 0; j < result[i].size(); j++){
			cout << result[i][j] << endl;
		}
		cout << endl;
	}
}
