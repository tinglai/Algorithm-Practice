#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution{
public:
    vector<vector<int> > permuteUnique(vector<int> &num){
		vector<vector<int>> result;
		vector<int> tempRes;
		int size = (int)num.size();
		unordered_map<int, int> memo;
		for(int i = 0; i < size; i++){
			memo[num[i]]++;
		}
		help(result, tempRes, memo, size);
		return result;
    }
	void help(vector<vector<int>>& result, vector<int>& tempRes, unordered_map<int, int>& memo, int size){
		if((int)tempRes.size() == size){
			result.push_back(tempRes);
			return;
		}

		for(unordered_map<int, int>::iterator i = memo.begin(); i != memo.end(); i++){
			if(i->second > 0){
				vector<int> res = tempRes;
				res.push_back(i->first);
				i->second--;
				help(result, res, memo, size);
				i->second++;
			}
		}
	}
};

int main(){
	vector<int> num = {};
	Solution soln;
	vector<vector<int>> result = soln.permuteUnique(num);
	for(unsigned int i = 0; i < result.size(); i++){
		for(unsigned int j = 0; j < result[i].size(); j++){
			cout << result[i][j] << " ";
		}
		cout << endl;
	}
}
