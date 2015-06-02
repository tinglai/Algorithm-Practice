#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution{
public:
    bool containsDuplicate(vector<int>& nums){
		unordered_set<int> memo;
		for(unsigned int i = 0; i < nums.size(); i++){
			if(memo.count(nums[i])) return true;
			memo.insert(nums[i]);
		}
		return false;
    }
};

int main(){
	vector<int> nums = {1};
	//vector<int> nums = {1,2,3,54,22};
	Solution soln;
	bool result = soln.containsDuplicate(nums);
	if(result) cout << "yes" << endl;
	else cout << "no" << endl;
}
