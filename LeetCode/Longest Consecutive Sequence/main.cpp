#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int> &num) {
		unordered_set<int> store;
		for(unsigned int i = 0; i < num.size(); i++){
			store.insert(num[i]);
		}
		vector<int> candidates;
		for(unsigned int i = 0; i < num.size(); i++){
			if(store.count(num[i] - 1) == 0){
				candidates.push_back(num[i]);
			}
		}
		int result = 0;
		for(unsigned int i = 0; i < candidates.size(); i++){
			int temp = candidates[i];
			int tempLength = 1;
			while(store.count(temp + 1) != 0){
				temp++;
				tempLength++;
			}
			if(tempLength > result){
				result = tempLength;
			}
		}
		return result;
    }
};

int main(){
	vector<int> num = {100, 4, 200, 1, 3, 2};
	Solution soln;
	int result = soln.longestConsecutive(num);
	cout << "result = " << result << endl;
}
