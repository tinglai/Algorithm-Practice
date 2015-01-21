#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution{
public:
    vector<vector<int>> permute(vector<int> &num){
		//first assume in num, there is no replication
		//the brute force I come up with to deal with
		//the replication is to use a unordered_map and
		//associate each permutation with an unique key
		vector<vector<int>> result;
		help(0, num, result);
		return result;
    }
	void help(int idx, vector<int> &num, vector<vector<int>> &result){
		if(idx == (int)num.size()){
			result.push_back(num);
			return;
		}
		for(unsigned int i = idx; i < num.size(); i++){
			swap(num[i], num[idx]);
			help(idx + 1, num, result);
			swap(num[i], num[idx]);
		}
	}
};

int main(){
	vector<int> num = {1, 2, 3};
	Solution soln;
	vector<vector<int>> result = soln.permute(num);
	for(unsigned int i = 0; i < result.size(); i++){
		for(unsigned int j = 0; j < result[i].size(); j++){
			cout << result[i][j] << " ";
		}
		cout << endl;
	}
}
