#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    vector<vector<int>> generate(int numRows){
		vector<vector<int>> result(numRows);
		for(int i = 0; i < numRows; i++){
			result[i].push_back(1);
			for(int j = 0; j < i - 1; j++){
				result[i].push_back(result[i - 1][j] + result[i - 1][j + 1]);
			}
			if(i > 0) result[i].push_back(1);
		}
		return result;
    }
};

int main(){
	int numRows;
	cout << "numRows = "; cin >> numRows;
	Solution soln;
	vector<vector<int>> result = soln.generate(numRows);
	for(unsigned int i = 0; i < result.size(); i++){
		for(unsigned int j = 0; j < result[i].size(); j++){
			cout << result[i][j] << " ";
		}
		cout << endl;
	}
}
