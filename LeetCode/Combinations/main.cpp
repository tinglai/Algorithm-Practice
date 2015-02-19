#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    vector<vector<int> > combine(int n, int k){
		vector<vector<int>> result;
		if(n < k) return result;
		vector<int> tempRes;
		vector<bool> memo(n, false);
		help(result, tempRes, memo, 0, k);
		return result;
    }
	void help(vector<vector<int>>& result, vector<int>& tempRes, vector<bool>& memo, int idx, int k){
		if(k == 0){
			vector<int>& toPush = tempRes;
			result.push_back(toPush);
			return;
		}
		for(unsigned int i = idx; i < memo.size(); i++){
			if(memo[i] == false){ // have not been visited yet
				tempRes.push_back(i + 1);
				memo[i] = true;
				help(result, tempRes, memo, i + 1, k - 1);
				tempRes.pop_back();
				memo[i] = false;
			}
		}
	}
};

int main(){
	int n, k;
	cout << "n = "; cin >> n;
	cout << "k = "; cin >> k;
	Solution soln;
	vector<vector<int>> result = soln.combine(n, k);
	for(unsigned int i = 0; i < result.size(); i++){
		for(unsigned int j = 0; j < result[i].size(); j++){
			cout << result[i][j] << " ";
		}
		cout << endl;
	}
}
