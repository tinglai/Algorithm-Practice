#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
	bool searchMatrix(vector<vector<int> > &matrix, int target){
		if(matrix.empty()) return false;
		if(matrix[0].empty()) return false;
		if(target > (matrix.back()).back()) return false;
		if(target < matrix[0][0]) return false;
		int rowIdx = help1(0, (int)matrix.size() - 1, matrix, target);
		return help(0, (int)matrix[rowIdx].size() - 1, matrix[rowIdx], target);
	}
	int help1(int a, int b, vector<vector<int>>& matrix, int target){
		// assume target is among [matrix[a].back(), matrix[b].back()]
		if(b - a <= 1){
			if(matrix[a].back() >= target) return a;
			else return b;
		}
		int mid = (a + b) / 2;
		if(target > matrix[mid].back()){
			return help1(mid + 1, b, matrix, target);
		}
		else{
			return help1(a, mid, matrix, target);
		}
	}
	bool help(int a, int b, vector<int>& row, int target){
		if(a > b) return false;
		int mid = (a + b) / 2;
		if(row[mid] == target) return true;
		else if(target > row[mid]){
			return help(mid + 1, b, row, target);
		}
		else{
			return help(a, mid - 1, row, target);
		}
	}
};

int main(){
	vector<vector<int>> matrix = {
									{1,3,5,7},
									{10,10,10,10},
									{23,30,34,50}
								};
	int target = 10;
	Solution soln;
	bool result = soln.searchMatrix(matrix, target);
	if(result) cout << "yes" << endl;
	else cout << "no" << endl;
}
