#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    void setZeroes(vector<vector<int> > &matrix){
		bool firstColumnHasZero = false;
		bool firstRowHasZero = false;
		for(unsigned int i = 0; i < matrix.size(); i++){
			if(matrix[i][0] == 0){
				firstColumnHasZero = true;
				break;
			}
		}
		for(unsigned int j = 0; j < matrix[0].size(); j++){
			if(matrix[0][j] == 0){
				firstRowHasZero = true;
				break;
			}
		}
		for(unsigned int i = 1; i < matrix.size(); i++){
			for(unsigned int j = 1; j < matrix[i].size(); j++){
				if(matrix[i][j] == 0){
					matrix[i][0] = 0;
					matrix[0][j] = 0;
				}
			}
		}
		for(unsigned int i = 1; i < matrix.size(); i++){
			if(matrix[i][0] == 0){
				for(unsigned int j = 1; j < matrix[i].size(); j++){
					matrix[i][j] = 0;
				}
			}
		}
		for(unsigned int j = 1; j < matrix[0].size(); j++){
			if(matrix[0][j] == 0){
				for(unsigned int i = 1; i < matrix.size(); i++){
					matrix[i][j] = 0;
				}
			}
		}
		if(firstColumnHasZero){
			for(unsigned int i = 0; i < matrix.size(); i++){
				matrix[i][0] = 0;
			}
		}
		if(firstRowHasZero){
			for(unsigned int i = 0; i < matrix[0].size(); i++){
				matrix[0][i] = 0;
			}
		}
    }
};

int main(){
	vector<vector<int>> matrix = {
									{9,0,8,1,3,9,0},
									{8,4,7,5,0,2,4},
									{8,4,6,7,1,2,3},
									{0,4,6,7,1,2,3}
								 };
	Solution soln;
	soln.setZeroes(matrix);
	for(unsigned int i = 0; i < matrix.size(); i++){
		for(unsigned int j = 0; j < matrix[i].size(); j++){
			cout << matrix[i][j] << ' ';
		}
		cout << endl;
	}
}
