#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution{
public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
		vector<vector<int>> result;
		if(candidates.empty()) return result;
		sort(candidates.begin(), candidates.end());
		vector<int> tempRes;
		int endIdx = help2(0, candidates.size() - 1, candidates, target);
		help(result, tempRes, candidates, target, endIdx);
		return result;
    }
	void help(vector<vector<int>>& result, vector<int>& tempRes, vector<int>& candidates, int target, int endIdx){
		if(target == 0){
			vector<int> toPush;
			for(int i = (int)tempRes.size() - 1; i > -1; i--){
				toPush.push_back(tempRes[i]);
			}
			result.push_back(toPush);
			return;
		}

		if(endIdx == -1) return;

		int last = 0;
		tempRes.push_back(candidates[last]);
		int nextIdx = help2(0, last, candidates, target - candidates[last]);
		help(result, tempRes, candidates, target - candidates[last], nextIdx);
		tempRes.pop_back();

		for(int i = 1; i <= endIdx; i++){
			if(candidates[i] == candidates[last]) continue;
			tempRes.push_back(candidates[i]);
			int nextIdx = help2(0, i, candidates, target - candidates[i]);
			help(result, tempRes, candidates, target - candidates[i], nextIdx);
			tempRes.pop_back();
			last = i;
		}
	}
	int help2(int a, int b, vector<int>& candidates, int target){
		if(target >= candidates[b]) return b;
		if(target < candidates[a]) return -1;
		if(a > b) return -1;
		if(b - a <= 1){
			if(candidates[b] == target) return b;
			else return a;
		}
		int mid = (a + b) / 2;
		if(candidates[mid] > target) return help2(a, mid - 1, candidates, target);
		else return help2(mid, b, candidates, target);
	}
};

int main(){
	vector<int> candidates = {1,2, 3, 6, 7};
	int target = 7;
	Solution soln;
	vector<vector<int>> result = soln.combinationSum(candidates, target);
	for(unsigned int i = 0; i < result.size(); i++){
		for(unsigned int j = 0; j < result[i].size(); j++){
			cout << result[i][j] << " ";
		}
		cout << endl;
	}
}
