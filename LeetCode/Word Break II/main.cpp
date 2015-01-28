#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<string> wordBreak(string s, unordered_set<string> &dict) {
		vector<string> result;
		if(s.empty()) return result;
		int size = (int)s.size();
	
//logic:
//given substring of s, ending at i, 
//cut it into two strings, s1, s2 with correspond
//lengths, l1, l2. l1: from 0 to i + 1, l2 from i + 1 to 0
//check if s2 is in dict and if s1 can be seperated using words in dict
//if both condition are true, memo[i] = l1;
//e.g:
//s = ihaveadog
//dic = {i, have, a, dog}
//memo[8] = 5, cut s into "ihavea" and "dog", dog is from the dict and
//"ihavea" can be broken approapriately
//memo[0] = 0, when l1 = 0, it always can be broken, s2 = "i", both condns are true
//
//REMARK:
//for thos question asking about breaking string, using substring's length is sometimes
//easier than using index

		vector<vector<int>> memo(size + 1);
		for(int i = 0; i < size; i++){
			for(int j = 0; j <= i + 1; j++){
				string tempStr = s.substr(j, i - j + 1);
				if(dict.count(tempStr) != 0){
					if(j == 0) memo[i].push_back(0);
					else if(memo[j - 1].size() > 0) memo[i].push_back(j);
				}
			}
		}
		vector<string> tempRes;
		help(result, size - 1, memo, tempRes, s);
		return result;
    }

	void help(vector<string>& result, int end, vector<vector<int>>& memo, vector<string>& tempRes, string& s){
		if(end == -1){
			string toPush;
			for(int i = (int)tempRes.size() - 1; i >= 0; i--){
				toPush += tempRes[i];
				toPush += " ";
			}
			toPush.pop_back();//deal with the last " "
			result.push_back(toPush);
			return;
		}		

		//if(memo[end].empty()) return;

		for(unsigned int i = 0; i < memo[end].size(); i++){
			string tempStr = s.substr(memo[end][i],  end - memo[end][i] + 1);
			tempRes.push_back(tempStr);
			help(result, memo[end][i] - 1, memo, tempRes, s);
			tempRes.pop_back();
		}
	}

};


int main(){
	//string s = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab";
	string s = "catsanddog";
	//unordered_set<string> dict = {"a", "aa", "aaa"};
	unordered_set<string> dict = {"cat", "cats", "and", "sand", "dog"};
	Solution soln;
	vector<string> result = soln.wordBreak(s, dict);
	for(unsigned int i = 0; i < result.size(); i++){
		cout << result[i] << endl;
	}
}
