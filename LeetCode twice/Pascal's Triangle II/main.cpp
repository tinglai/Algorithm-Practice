#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    vector<int> getRow(int rowIndex){
		vector<int> result;
		if(rowIndex < 0) return result;
		result.push_back(1);
		for(int i = 1; i <= rowIndex; i++){
			for(int j = result.size() - 1; j >= 1; j--){
				result[j] = result[j] + result[j - 1];
			}
			result.push_back(1);
		}
		return result;
    }
};

int main(){
	int rowIndex;
	cout << "rowIndex = ";
	cin >> rowIndex;
	Solution soln;
	vector<int> result = soln.getRow(rowIndex);
	for(unsigned int i = 0; i < result.size(); i++){
		cout << result[i] << " ";
	}
	cout << endl;
}
