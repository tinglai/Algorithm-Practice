#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution{
public:
    vector<vector<string>> partition(string s){
		int size = (int)s.size();
		vector<vector<string>> result;
		if(size == 0) return result;
		vector<vector<int>> memo(size + 1);
		memo[0].push_back(0);
		for(int i = 0; i < size; i++){
			for(int j = 0; j <= i; j++){
				string tempStr = s.substr(j, i - j + 1);
				if(memo[j].size() > 0 && isPalindrome(tempStr)){
					memo[i + 1].push_back(j);
				}
			}
		}
		vector<string> tempRes;
		backTrack(s, result, tempRes, memo, size);
		return result;
    }
	bool isPalindrome(string s){
		int size = (int)s.size();
		if(size <= 1) return true;
		int i = 0; 
		int j = size - 1;
		while(i < j){
			if(s[i] != s[j]) return false;
			i++;
			j--;
		}
		return true;
	}
	void backTrack(string& s, vector<vector<string>>& result, vector<string>& tempRes, vector<vector<int>>& memo, int n){
		if(n == 0){
			vector<string> toPush;
			int size = (int)tempRes.size();
			for(unsigned int i = 0; i < tempRes.size(); i++){
				toPush.push_back(tempRes[size - 1 - i]);
			}
			result.push_back(toPush);
			return;
		}
		for(unsigned int i = 0; i < memo[n].size(); i++){
			string tempStr = s.substr(memo[n][i], n - memo[n][i]);
			tempRes.push_back(tempStr);
			backTrack(s, result, tempRes, memo, memo[n][i]);
			tempRes.pop_back();
		}
	}
};

int main(){
	string s;
	cout << "s = "; cin >> s;
	Solution soln;
	vector<vector<string>> result = soln.partition(s);
	for(unsigned int i = 0; i < result.size(); i++){
		for(unsigned int j = 0; j < result[i].size(); j++){
			cout << result[i][j] << " ";
		}
		cout << endl;
	}
}