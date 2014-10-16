#include <iostream>
#include <vector>

using namespace std;

void checkZero(vector<vector<int>> &matrix){
	//using two vectors to record if corresponding row
	//or column needs to be set to zero
	vector<bool> row(matrix.size(), false);
	vector<bool> column(matrix[0].size(), false);
	for(unsigned int i = 0; i < matrix.size(); i++){
		for(unsigned int j = 0; j < matrix[0].size(); j++){
			if(matrix[i][j] == 0){
				row[i] = true;
				column[j] = true;
			}
		}
	}

	//nullify rows
	for(unsigned int i = 0; i < row.size(); i++){
		if(row[i] == true){
			for(unsigned int j = 0; j < column.size(); j++){
				matrix[i][j] = 0;
			}
		}
	}

	//nullify columns
	for(unsigned int j = 0; j < column.size(); j++){
		if(column[j] == true){
			for(unsigned int i = 0; i < row.size(); i++){
				matrix[i][j] = 0;
			}
		}
	}
}

void printMatrix(vector<vector<int>> &matrix){
	for(unsigned int i = 0; i < matrix.size(); i++){
		for(unsigned int j = 0; j < matrix[0].size(); j++){
			cout << matrix[i][j] << ' ';
		}
		cout << endl;
	}
}

int main(){
	vector<vector<int>> matrix = {{1,2,3,4}, {5,6,7,8}};
	vector<vector<int>> matrix2 = {{1,0,3,4}, {5,6,7,8}, {9,2,4,0}};
	cout << "before zero check" << endl;

	cout << "matrix: " << endl;
	printMatrix(matrix);

	cout << "matrix2: " << endl;
	printMatrix(matrix2);

	cout << "after zero check" << endl;

	checkZero(matrix);
	cout << "matrix: " << endl;
	printMatrix(matrix);

	checkZero(matrix2);
	cout << "matrix2: " << endl;
	printMatrix(matrix2);
}
