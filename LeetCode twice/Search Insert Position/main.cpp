#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
	int searchInsert(vector<int>& nums, int target){
		if(nums.empty()) return 0;
		if(target <= nums[0]) return 0;
		if(target > nums.back()) return nums.size();
		return help(0, nums.size() - 1, target, nums);
	}
	int help(int a, int b, int target, vector<int>& nums){
		if(b - a <= 1){
			if(target == nums[a]) return a;
			else return b;
		}
		int mid = (a + b) / 2;
		if(target == nums[mid]) return mid;
		else if(target < nums[mid]){
			return help(a, mid, target, nums);
		}
		else{
			return help(mid, b, target, nums);
		}
	}
};

int main(){
	vector<int> nums = {1, 3, 5, 6};
	int target;
	cout << "target = ";
	cin >> target;
	Solution soln;
	int result = soln.searchInsert(nums, target);
	cout << "result = " << result << endl;
}
