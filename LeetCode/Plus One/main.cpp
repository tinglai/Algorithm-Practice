#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
		vector<int> result = digits;
		result.back()++;
		int size = digits.size();
		for(unsigned int i = size - 1; i > 0; i--){
			if(result[i] == 10){
				result[i] = 0;
				result[i - 1]++;
			}
			else{
				break;
			}
		}
		if(result[0] == 10){
			result[0] = 0;
			result.insert(result.begin(), 1);
		}
		return result;
    }
};

int main(){
	//vector<int> digits = {1,2,3,4,5};
	//vector<int> digits = {9,9,9,9};
	vector<int> digits = {9,2,9,9};
	Solution soln;
	vector<int> result = soln.plusOne(digits);
	for(unsigned int i = 0; i < result.size(); i++){
		cout << result[i];
	}
	cout << endl;
}
