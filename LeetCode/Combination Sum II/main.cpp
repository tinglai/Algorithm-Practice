#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

struct MyComp{
	bool operator()(const int& a, const int& b){
		return a > b;
	}
} comp;

class Solution{
public:
    vector<vector<int> > combinationSum2(vector<int> &num, int target){
		sort(num.begin(), num.end());
		vector<vector<int>> result;
		vector<int> tempRes;
		int endIdx = help2(0, num.size() - 1, target, num);
		help(result, tempRes, num, endIdx, target);
		return result;
    }
	void help(vector<vector<int>>& result, vector<int>& tempRes, vector<int>& num, int endIdx, int target){
		if(target == 0){
			vector<int> toPush = tempRes;
			result.push_back(toPush);
			return;
		}

		if(endIdx == -1) return;

		int last = num[endIdx];
		tempRes.push_back(num[endIdx]);
		int nextEndIdx = help2(0, endIdx - 1, target - num[endIdx], num);
		help(result, tempRes, num, nextEndIdx, target - num[endIdx]);
		tempRes.pop_back();
		for(int i = endIdx - 1; i >= 0; i--){
			if(num[i] == last) continue;
			tempRes.push_back(num[i]);
			int next = help2(0, i - 1, target - num[i], num);
			help(result, tempRes, num, next, target - num[i]);
			tempRes.pop_back();
			last = num[i];
		}
	}
	int help2(int a, int b, int target, vector<int>& num){
	// binary search for the first idx s.t num[idx] <= target
		if(num[b] <= target) return b;
		if(num[a] > target) return -1;
		if(b < a) return -1;
		if(b - a <= 1){
			if(target == num[b]) return b;
			else return a;
		}
		int mid = (a + b) / 2;
		if(target >= num[mid]) return help2(mid, b, target, num);
		else return help2(a, mid - 1, target, num);
	}
};

int main(){
	vector<int> num = {1,2,2,2,5};
	int target = 5;
	Solution soln;
	vector<vector<int>> result = soln.combinationSum2(num, target);
	for(unsigned int i = 0; i < result.size(); i++){
		for(unsigned int j = 0; j < result[i].size(); j++){
			cout << result[i][j] << " ";
		}
		cout << endl;
	}
}
