#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    vector<int> getRow(int rowIndex){
		vector<int> result;
		if(rowIndex < 0) return result;
		//if(rowIndex == 0) return {1};
		result.resize(rowIndex + 1);
		for(int i = 0; i <= rowIndex; i++){
			result[0] = 1;
			result[i] = 1;
			for(int j = 1; j < i; j++){
				result[i - j] = result[i - j] + result[i - j - 1];
			}
		}
		return result;
    }
};

int main(){
	int rowIndex;
	cout << "rowIndex = "; cin >> rowIndex;
	Solution soln;
	vector<int> result = soln.getRow(rowIndex);
	for(unsigned int i = 0; i < result.size(); i++){
		cout << result[i] << " ";
	}
	cout << endl;
}
