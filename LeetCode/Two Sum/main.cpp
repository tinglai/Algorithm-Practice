#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution{
public:
    vector<int> twoSum(vector<int> &numbers, int target){
		vector<int> result;
		int n = (int)numbers.size();
		unordered_map<int, vector<int>> numbersMap;
		for(int i = 0; i < n; i++){
			numbersMap[numbers[i]].push_back(i);
		}
		for(int i = 0; i < n; i++){
			int needed = target - numbers[i];
			if(numbersMap.count(needed) == 0) continue;
			else{
				for(unsigned int j = 0; j < numbersMap[needed].size(); j++){
					int temp = numbersMap[needed][j];
					if(temp == i) continue;
					else{
						if(i < temp){
							result.push_back(i + 1);
							result.push_back(temp + 1);
						}
						else{
							result.push_back(temp + 1);
							result.push_back(i + 1);
						}
						return result;
					}
				}
			}
		}
		return result;
    }
};

int main(){
	vector<int> numbers = {0,4,3,0};
	int target = 0;
	Solution soln;
	vector<int> result = soln.twoSum(numbers, target);
	for(unsigned int i = 0; i < result.size(); i++){
		cout << result[i] << endl;
	}
}
