#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>

using namespace std;

class Solution{
public:
    vector<vector<int>> subsetsWithDup(vector<int> &S){
		vector<vector<int>> result;
		if(S.empty()) return result;
		set<int> nums;
		unordered_map<int, int> times;
		for(unsigned int i = 0; i < S.size(); i++){
			nums.insert(S[i]);
			times[S[i]]++;
		}
		vector<int> tempRes;
		help(result, tempRes, times, nums, nums.begin());
		return result;
    }
	void help(vector<vector<int>>& result, vector<int>& tempRes, unordered_map<int, int>& times, set<int>& nums, set<int>::iterator itr){
		if(itr == nums.end()){
			result.push_back(tempRes);
			return;
		}
		
		set<int>::iterator next = itr;
		next++;
		
		for(int i = 0; i <= times[*itr]; i++){
			vector<int> toPush = tempRes;
			help(result, toPush, times, nums, next);
			tempRes.push_back((*itr));
		}
	}
};

int main(){
	vector<int> S = {1};
	//vector<int> S = {1, 2, 2};
	Solution soln;
	vector<vector<int>> result = soln.subsetsWithDup(S);
	for(unsigned int i = 0; i < result.size(); i++){
		for(unsigned int j = 0; j < result[i].size(); j++){
			cout << result[i][j] << " ";
		}
		cout << endl;
	}
}
