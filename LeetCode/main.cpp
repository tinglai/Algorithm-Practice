#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

class Solution{
public:
    vector<string> restoreIpAddresses(string s){
		vector<string> result;
		vector<string> tempRes;
		help(result, s, 4, 0, tempRes);
		return result;
	}
	void help(vector<string>& result, string& s, int remain, int n, vector<string>& tempRes){
		int subStrSize = (int)s.size() - n;
		if(subStrSize > 3 * remain || subStrSize < remain){
			return;
		}

		if(remain == 0){
			if(n != (int)s.size()) return;
			else{
				string toPush;
				toPush += tempRes[0];
				for(unsigned int i = 1; i < tempRes.size(); i++){
					toPush += ".";
					toPush += tempRes[i];
				}
				result.push_back(toPush);
				return;
			}
		}

		for(int i = 0; i < 3; i++){
			string tempStr = s.substr(n, i + 1);
			int temp = stoi(tempStr);
			if(temp == 0){
				tempRes.push_back(tempStr);
				help(result, s, remain - 1, n + i + 1, tempRes);
				tempRes.pop_back();
				break;
			}
			else if(temp < 256){
				tempRes.push_back(tempStr);
				help(result, s, remain - 1, n + i + 1, tempRes);
				tempRes.pop_back();
			}
		}
	}
};
/*
		int size = (int)s.size();
		vector<string> result;
		if(size > 12 || size < 4) return result;
		vector<vector<vector<int>>> memo(4, vector<vector<int>>(size + 1));
		memo[0].push_back(0);;

		int remain = 4;
		for(int t = 0; t < 4; t++){
			
		}
		vector<string> tempRes;
		help(result, s, tempRes, size, memo);
		return result;
    }

	void help2(vector<vector<int>>& memo, string& s, int t){
		int size = (int)s.size();
		int remain = 4 - t;
		//if(size - n - 1 > 3 * remain || size - n - 1 < remain) return;

	for(int i = )
		for(int j = max(i - 2, 0); j < i + 1; j++){
			string tempStr = s.substr(j, i - j + 1);
			int temp = stoi(tempStr);
			if(temp < 256 && memo[j].size() > 0){
				memo[i + 1].push_back(j);
			}
		}
	
		for(int i = n + 1; i < min(size, n + 4); i++){
		}
	}

	void help(vector<string>& result, string& s, vector<string>& tempRes, int n, vector<vector<int>> memo){
		if(n == 0){
			string toPush = s;
			if(tempRes.size() > 0) toPush += tempRes[0];
			for(int i = (int)tempRes.size() - 1; i > 0; i--){
				toPush += ".";
				toPush += tempRes[i];
			}
			return;
		}

		for(unsigned int i = 0; i < memo[n].size(); i++){
			string tempStr = s.substr(memo[n][i], n - memo[n][i]);
			tempRes.push_back(tempStr);
			help(result, s, tempRes, memo[n][i], memo);
			tempRes.pop_back();
		}
	}
};
*/
int main(){
	//string s = "25525511135";
	string s = "010010";
	//cout << "s = "; cin >> s;
	
	Solution soln;
	vector<string> result = soln.restoreIpAddresses(s);
	for(unsigned int i = 0; i < result.size(); i++){
		cout << result[i] << endl;
	}
}
