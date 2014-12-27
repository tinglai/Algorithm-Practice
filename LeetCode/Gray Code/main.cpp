#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Solution {
//For this question, there is a trick. That is,
//when n = 0, result = {0}
//when n = 1, result = {0, 1}
//when n = 2, result = {00, 01, 11, 10}
//when n = 3, result = {000, 001, 011, 010,
//						100, 101, 111, 110}
//every time, when n is added by 1, i.e when n = k + 1, it turns out
//that to add 2^(k) to the original list of 
//result in the case n = k
public:
    vector<int> grayCode(int n) {
		vector<int> result = {0};
		if(n < 0){
			cout << "n cannot be negative" << endl;
			return result;
		}
		int temp;
		for(int i = 0; i < n; i++){
			int size = result.size();
			for(int j = size - 1; j >= 0; j--){
				temp = result[j] + pow(2, i);
				result.push_back(temp);
			}
		}
		return result;
    }
};

int main(){
	int n;
	cout << "n = ";
	cin >> n;
	Solution soln;
	vector<int> result = soln.grayCode(n);
	for(unsigned int i = 0; i < result.size(); i++){
		cout << result[i] << ' ';
	}
	cout << endl;
}
