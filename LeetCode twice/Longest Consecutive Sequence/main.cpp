#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution{
public:
	int longestConsecutive(vector<int>& nums){
		int result = 0;
		unordered_set<int> memo;
		int a, b;
		for(unsigned int i = 0; i < nums.size(); i++){
			memo.insert(nums[i]);
		}
		while(!memo.empty()){
			a = *(memo.begin());
			b = a;
			int tempresult = 1;
			memo.erase(*(memo.begin()));
			while(memo.count(a - 1)){
				tempresult++;
				memo.erase(a - 1);
				a--;
			}
			while(memo.count(b + 1)){
				tempresult++;
				memo.erase(b + 1);
				b++;
			}
			if(tempresult > result) result = tempresult;
			if(memo.size() < result) return result;
		}
		return result;
	}
};

int main(){
	vector<int> num = {100, 200, 1,4,3,2};
	Solution soln;
	int result = soln.longestConsecutive(num);
	cout << "result = " << result << endl;
}
