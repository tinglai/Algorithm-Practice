#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution{
public:
	vector<vector<int>> threeSum(vector<int>& nums){
		vector<int> temp(nums);
		sort(temp.begin(), temp.end());
		vector<vector<int>> result;
		if(nums.size() < 3) return result;
		int i = 0;
		while(i < temp.size() - 2){
			help(temp, i + 1, -temp[i], result);
			i++;
			while(i < temp.size() && temp[i] == temp[i - 1]) i++;
		}
		return result;
	}
	void help(vector<int>& temp, int idx, int target, vector<vector<int>>& result){// actually this is sort of a two sum function
		int a = idx;
		int b = temp.size() - 1;
		while(a < b){
			int sum = temp[a] + temp[b];
			if(sum == target){
				result.push_back({-target, temp[a], temp[b]});
				b--;
				a++;
				while(b > idx && temp[b] == temp[b + 1]){
					b--;
				}
				while(a < temp.size() - 1 && temp[a] == temp[a - 1]){
					a++;
				}
			}
			else if(sum > target){
				b--;
				while(b > idx && temp[b] == temp[b + 1]){
					b--;
				}
			}
			else{
				a++;
				while(a < temp.size() - 1 && temp[a] == temp[a - 1]){
					a++;
				}
			}
		}
	}
};

int main(){
	//vector<int> nums = {-1, 0, 1, 2, -1, -4};
	vector<int> nums = {0,0,0,0,0,0,0,0,0,0};
	Solution soln;
	vector<vector<int>> result = soln.threeSum(nums);
	for(int i = 0; i < result.size(); i++){
		for(int j = 0; j < result[i].size(); j++){
			cout << result[i][j] << ' ';
		}
		cout << endl;
	}
}
