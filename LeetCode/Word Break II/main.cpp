#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;
/*
class Solution{
public:
    vector<string> wordBreak(string s, unordered_set<string> &dict){
		int size = (int)s.size();
		vector<vector<int>> memo;
		for(int i = 0; i < size; i++){
			vector<int> in;
			memo.push_back(in);
			for(int j = i; j < size; j++){
				string tempStr = s.substr(i, j - i + 1);
				if(dict.count(tempStr) != 0){
					memo[i].push_back(j);
				}
			}
			if(memo[i].empty()){
cout << ")))))" << i << endl;
			}
		}
		vector<string> result;
		string sentence;
		help2(result, memo, 0, s, sentence);
		return result;
    }

	void help2(vector<string>& result, vector<vector<int>>& memo, int start, string& s, string& sentence){
		if(start == ((int)s.size())){
			result.push_back(sentence);
			return;
		}
		if(memo[start].empty()) return;
		for(unsigned int i = 0; i < memo[start].size(); i++){
			string toPush = sentence;
			if(start != 0){
				toPush += " ";
			}
			toPush += s.substr(start, memo[start][i] - start + 1);
			help2(result, memo, memo[start][i] + 1, s, toPush);
		}
		return;
	}
};
*/
class Solution {
public:
    vector<string> wordBreak(string s, unordered_set<string> &dict) {
        vector<string> res;
        if (dict.size() == 0) return res;

        vector<vector<int> > spaceIdx;
        spaceIdx.resize(s.size() + 1);
        spaceIdx[0].push_back(-1);

        for (int i = 1; i <= s.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (spaceIdx[j].size() && dict.count(s.substr(j, i - j))) {
                        spaceIdx[i].push_back(j);
                }
            }
        }

        return backTrack(s, spaceIdx, s.size());
    }

    vector<string> backTrack(string& s, vector<vector<int> >& spaceIdx, int idx) {
        vector<string> res;
        if (idx <= 0) {res.push_back(""); return res;}

        for (int i = 0; i < spaceIdx[idx].size(); i++) {
            string str = s.substr(spaceIdx[idx][i], idx - spaceIdx[idx][i]);
            vector<string> subRes = backTrack(s, spaceIdx, spaceIdx[idx][i]);
            for (int j = 0; j < subRes.size(); j++) {
                if (subRes[j] != "") subRes[j] = subRes[j] + " " + str;
                else subRes[j] = str;
                res.push_back(subRes[j]);
            }
        }

        return res;
    }
};

int main(){
	string s = "baaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
	//string s = "catsanddog";
	unordered_set<string> dict = {"a", "aa", "aaa"};
	//unordered_set<string> dict = {"cat", "cats", "and", "sand", "dog"};
	//cout << "s = "; cin >> s;
	Solution soln;
	vector<string> result = soln.wordBreak(s, dict);
	for(unsigned int i = 0; i < result.size(); i++){
		cout << result[i] << endl;
	}
}
