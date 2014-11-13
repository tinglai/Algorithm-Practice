#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void rotate(vector<vector<int> > &matrix) {
		if(matrix.empty()) return;
		int offset = 0;
		int n = matrix.size();
		int length = n - 1;
		int temp;
		while(length > 0){
			for(int i = 0; i < length; i++){
				temp = matrix[n - 1 - i - offset][offset];
				matrix[n - 1 - offset - i][offset] = matrix[n - 1 - offset][n - 1 - offset - i];
				matrix[n - 1 - offset][n - 1 - i - offset] = matrix[i + offset][n - 1 - offset];
				matrix[i + offset][n - 1 - offset] = matrix[offset][i + offset];
				matrix[offset][i + offset] = temp;
			}
			length -= 2;
			offset++;
		}
    }
};

void print(vector<vector<int>>& matrix){
	for(unsigned int i = 0; i < matrix.size(); i++){
		for(unsigned int j = 0; j < matrix[i].size(); j++){
			cout << matrix[i][j] << ' ';
		}
		cout << endl;
	}
}

int main(){
	vector<vector<int>> matrix = {{1,2,3,4, -1}, {5,6,7,8, -2}, {9, 10, 11, 12, 0}, {13, 14, 15, 16, -3}, 
								    {17, 18, 19, 20, 21}};
	cout << "The original matrix is as following" << endl;
	print(matrix);
	Solution solt;
	solt.rotate(matrix);
	cout << "After rotation, the matrix is as following" << endl;
	print(matrix);
}
