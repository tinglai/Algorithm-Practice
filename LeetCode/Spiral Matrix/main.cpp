#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

class Solution{
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix){
		vector<int> result;
		if(matrix.empty()) return result;
		int m = (int)matrix.size();
		int n = (int)matrix[0].size();
		for(int i = 0; i < min(m, n) / 2; i++){
			for(int j = i; j < n - 1 - i; j++){
				result.push_back(matrix[i][j]);
			}
			for(int j = i; j < m - 1 - i; j++){
				result.push_back(matrix[j][n - 1 - i]);
			}
			for(int j = n - 1 - i; j > i; j--){
				result.push_back(matrix[m - 1 - i][j]);
			}
			for(int j = m - 1 - i; j > i; j--){
				result.push_back(matrix[j][i]);
			}
		}
		if(min(m, n) % 2 == 1){
			if(m < n){
				for(int i = m / 2; i < n - m / 2; i++){
					result.push_back(matrix[m / 2][i]);
				}
			}
			else{
				for(int i = n / 2; i < m - n / 2; i++){
					result.push_back(matrix[i][n / 2]);
				}
			}
		}
		return result;
    }
};

int main(){
/*	vector<vector<int>> matrix = {
									{1,2,3,4},
									{5,6,7,8},
									{9,10,11,12},
									{13,14,15,16},
								};
*/
	vector<vector<int>> matrix = {
								};
	Solution soln;
	vector<int>result = soln.spiralOrder(matrix);
	for(unsigned int i = 0; i < result.size(); i++){
		cout << result[i] << " ";
	}
	cout << endl;
}
