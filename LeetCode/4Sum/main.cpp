#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
		sort(num.begin(), num.end());
		vector<vector<int>> result;
		int aIdx = 0;//here aIdx is the index of the  minimun of the quadruplets
		int bIdx = num.size() - 1;//here bIdx is the indxe of the maximum of the quadruplets
		//fixed the minimum and maximum of the quadruplets, I search through the rest of the numebrs
		//for the remaining two numbers s.t the 4sum is equal to the target
		int size = num.size();
		for(aIdx = 0; aIdx < size - 1 - 2; aIdx++){
			if(aIdx > 0 && num[aIdx] == num[aIdx - 1]) continue;
			//there might be multipul same numbers which can be the minimum
			for(bIdx = size - 1; bIdx > aIdx + 2; bIdx--){
				if(bIdx < size - 1 && num[bIdx] == num[bIdx + 1]) continue;
				//there might be multipul same numbers which can be the maximum
				int twoSumTarget;

				twoSumTarget = target - num[aIdx] - num[bIdx];
				vector<vector<int>> twoSumResult = twoSum(num, twoSumTarget, aIdx + 1, bIdx - 1);
				if(!twoSumResult.empty()){
					for(unsigned int i = 0; i < twoSumResult.size(); i++){
						vector<int> in = {num[aIdx], twoSumResult[i][0], twoSumResult[i][1], num[bIdx]};
						result.push_back(in);
					}
				}
			}//in for
		}//out for
		return result;
    }
	vector<vector<int>> twoSum(vector<int> &num, int target, int aIdx, int bIdx){
		vector<vector<int>> result;
		while(aIdx < bIdx){
			if(num[aIdx] + num[bIdx] == target){
				vector<int> in = {num[aIdx], num[bIdx]};
				result.push_back(in);

				while(num[aIdx] == num[aIdx + 1]){
					aIdx++;
				}
				while(num[bIdx] == num[bIdx - 1]){
					bIdx--;
				}
				aIdx++;
				bIdx--;
			}
			else{
				if(num[aIdx] + num[bIdx] > target){
					bIdx--;
				}
				else{
					aIdx++;
				}
			}
		}
		return result;
	}
};

int main(){
	//vector<int> num = {1, 0, -1, 0, -2, 2};
	vector<int> num = {5,5,3,5,1,-5,1,-2};
	Solution soln;
	int target = 4;
	vector<vector<int>> result = soln.fourSum(num, target);
	for(unsigned int i = 0; i < result.size(); i++){
		for(unsigned int j = 0; j < result[i].size(); j++){
			cout << result[i][j] << ' ';
		}
		cout << endl;
	}
}
