#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution{
public:
	vector<vector<int>> permuteUnique(vector<int>& nums){
		vector<vector<int>> result;
		if(nums.empty()) return result;
		vector<int> temp(nums);
		help(result, temp, 0);
		return result;
	}
	void help(vector<vector<int>>& result, vector<int> nums, int idx){
		if(idx == nums.size() - 1){
			vector<int> in;
			for(unsigned int t = 0; t < nums.size(); t++){
				in.push_back(nums[t]);
			}
			result.push_back(in);
			return;
		}
		sort(nums.begin() + idx, nums.end());

		help(result, nums, idx + 1);
		for(unsigned int i = idx + 1; i < nums.size();){
			if(nums[i] == nums[idx]){
				i++;
				continue;
			}
			swap(nums[i], nums[idx]);
			help(result, nums, idx + 1);
			swap(nums[i], nums[idx]);
			i++;
			while(i < nums.size() && nums[i] == nums[i - 1]){
				i++;
			}
		}
	}
};

int main(){
	vector<int> nums = {3,1,2,1};
	Solution soln;
	vector<vector<int>> result = soln.permuteUnique(nums);
	for(unsigned int i = 0; i < result.size(); i++){
		for(unsigned int j = 0; j < result[i].size(); j++){
			cout << result[i][j] << ' ';
		}
		cout << endl;
	}
}
