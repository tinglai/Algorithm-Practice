#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution{
public:
    vector<vector<int>> subsets(vector<int> &S){
		vector<vector<int>> result;
		if(S.empty()) return result;
		sort(S.begin(), S.end());
		vector<int> tempRes;
		help(result, 0, S, tempRes);
		return result;
    }
	void help(vector<vector<int>>& result, int idx, vector<int>& S, vector<int>& tempRes){
		if(idx == (int)S.size()){
			vector<int> toPush = tempRes;
			result.push_back(toPush);
			return;
		}

		vector<int> curRes = tempRes;
		help(result, idx + 1, S, curRes);
		tempRes.push_back(S[idx]);
		help(result, idx + 1, S, tempRes);
	}
};

int main(){
	vector<int> S = {4, 1, 0};
	Solution soln;
	vector<vector<int>> result = soln.subsets(S);
	for(unsigned int i = 0; i < result.size(); i++){
		for(unsigned int j = 0; j < result[i].size(); j++){
			cout << result[i][j] << " ";
		}
		cout << endl;
	}
}
