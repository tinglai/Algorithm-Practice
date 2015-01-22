#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution{
public:
    vector<vector<int>> threeSum(vector<int> &num){
		vector<vector<int>> result;
		if(num.size() < 3) return result;
		sort(num.begin(), num.end());
		for(unsigned int i = 0; i < num.size(); i++){
			help(result, num, i);
		}
		return result;
    }
	void help(vector<vector<int>>& result, vector<int>& num, int targetIdx){
		if(targetIdx > 0 && (num[targetIdx - 1] == num[targetIdx])){
			return;
			//deal with duplicated numbers in vector num
			//if in num, there are duplicates, we ignore the case in
			//which the duplicates are targetIdx, since those cases have
			//been considered
		}
		int a = targetIdx + 1;//start targetIdx + 1 to avoid duplicates
		int b = (int)num.size() - 1;
		while(a < b){
			int sum = num[a] + num[b];
			if(sum < (-1 * num[targetIdx])){
				a++;
				while(a < b && num[a] == num[a - 1]){
					a++; 
				}
			}
			else if(sum > (-1 * num[targetIdx])){
				b--;
				while(a < b && num[b] == num[b + 1]){
					b--;
				}
			}
			else{
				vector<int> toPush;
				toPush.push_back(num[targetIdx]);
				toPush.push_back(num[a]);
				toPush.push_back(num[b]);
				a++;
				while(a < b && num[a] == num[a - 1]){
					a++;
					//move to the next number other than num[a]
				}
				b--;
				while(a < b && num[b] == num[b + 1]){
					b--;
				}
				result.push_back(toPush);
			}
		}
	}
};

int main(){
	//vector<int> num = {-1, 0, 1, 2, -2, 2, -1, -4};
	vector<int> num = {7,-1,14,-12,-8,7,2,-15,8,8,-8,-14,-4,-5,7,9,11,-4,-15,-6,1,-14,4,3,10,-5,2,1,6,11,2,-2,-5,-7,-6,2,-15,11,-6,8,-4,2,1,-1,4,-6,-15,1,5,-15,10,14,9,-8,-6,4,-6,11,12,-15,7,-1,-9,9,-1,0,-4,-1,-12,-2,14,-9,7,0,-3,-4,1,-2,12,14,-10,0,5,14,-1,14,3,8,10,-8,8,-5,-2,6,-11,12,13,-7,-12,8,6,-13,14,-2,-5,-11,1,3,-6};
	Solution soln;
	vector<vector<int>> result = soln.threeSum(num);
	for(unsigned int i = 0; i < result.size(); i++){
		for(unsigned int j = 0; j < result[i].size(); j++){
			cout << result[i][j] << " ";
		}
		cout << endl;
	}
}
