#include <iostream>
#include <vector>

using namespace std;

void rotate(vector<int> &matrix, int length){
	int temp;
	for(int i = 0; i < length / 2; i++){
		for(int j = i; j < length - 1 - i; j++){
			temp = matrix[i * length + j];
			matrix[i * length + j] =
			   matrix[(length - 1 - j) * length + i];
			   //[length - 1 - j, i] -> [i, j]
			matrix[(length - 1 - j) * length + i] = 
			   matrix[(length - 1 - i) * length + length - 1 - j];
			   //[length - 1 - i, length - 1 - j] -> [length - 1 - j, i]
			matrix[(length - 1 - i) * length + length - 1 - j] =
			   matrix[j * length + (length - 1 - i)];
			   //[j, length - 1 - i] -> [length - 1 - i, length - 1 - j]
			matrix[j * length + (length - 1 - i)] = 
			   temp;
			   //[i, j] -> [length - 1 - i, j]
		}
	}
}

int main(){
	vector<int> matrix;
	int length = 4;
	for(int i = 1; i <= length * length; i++){
		matrix.push_back(i);
	}
	cout << "before rotation:" << endl;
	for(int i = 0; i < length; i++){
		for(int j = 0; j < length; j++){
			cout << matrix[i * length + j] << ' ';
		}
		cout << endl;
	}

	rotate(matrix, length);
	cout << "after rotation:" << endl;
	for(int i = 0; i < length; i++){
		for(int j = 0; j < length; j++){
			cout << matrix[i * length + j] << ' ';
		}
		cout << endl;
	}

}
