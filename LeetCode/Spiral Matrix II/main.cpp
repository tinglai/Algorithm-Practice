#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    vector<vector<int> > generateMatrix(int n){
		if(n <= 0){
			vector<vector<int>> null;
			return null;
		}
		vector<vector<int>> result(n, vector<int>(n));
		int curN = 1;
		int layer = 0;
		while(true){
			help(layer, result, curN, n);
			if(layer == (n / 2)) break;
			layer++;
		}
		if(n % 2 == 1) result[n / 2][n / 2] = n * n;
		return result;
    }
	void help(int layer, vector<vector<int>>& matrix, int& curN, int n){
		int length = n - 1 - 2 * layer;
		for(int i = 0; i < length; i++){
			matrix[layer][layer + i] = curN++;
		}
		for(int i = 0; i < length; i++){
			matrix[layer + i][n - 1 - layer] = curN++;
		}
		for(int i = 0; i < length; i++){
			matrix[n - 1 - layer][n - 1 - layer - i] = curN++;
		}
		for(int i = 0; i < length; i++){
			matrix[n - 1 - layer - i][layer] = curN++;
		}
	}
};

int main(){
	int n;
	cout << "n = ";
	cin >> n;
	Solution soln;
	vector<vector<int>> result = soln.generateMatrix(n);
	for(unsigned int i = 0; i < result.size(); i++){
		for(unsigned int j = 0; j < result[i].size(); j++){
			cout << result[i][j] << " ";
		}
		cout << endl;
	}
}
