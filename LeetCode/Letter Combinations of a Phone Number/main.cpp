#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution{
public:
    vector<string> letterCombinations(string digits){
		vector<string> result;
		if(digits.empty()) return {""};
		unordered_map<char, vector<char>> dict;
		dict['2'] = {'a', 'b', 'c'};
		dict['3'] = {'d', 'e', 'f'};
		dict['4'] = {'g', 'h', 'i'};
		dict['5'] = {'j', 'k', 'l'};
		dict['6'] = {'m', 'n', 'o'};
		dict['7'] = {'p', 'q', 'r', 's'};
		dict['8'] = {'t', 'u', 'v'};
		dict['9'] = {'w', 'x', 'y', 'z'};
		dict['0'] = {' '};

		string tempRes;
		help(result, tempRes, digits, dict, 0);
		return result;
    }
	void help(vector<string>& result, string& tempRes, string& digits, 
			     unordered_map<char, vector<char>>& dict, int n){
		
		if(n == (int)digits.size()){
			string toPush = tempRes;
			result.push_back(toPush);
			return;
		}

		char curDig = digits[n];

		if(dict.count(curDig) == 0){
			help(result, tempRes, digits, dict, n + 1);
		}
		else{
			for(unsigned int i = 0; i < dict[curDig].size(); i++){
				tempRes.push_back(dict[curDig][i]);
				help(result, tempRes, digits, dict, n + 1);
				tempRes.pop_back();
			}
		}
	}
};

int main(){
	string digits;
	cout << "digits = "; cin >> digits;
	Solution soln;
	vector<string> result = soln.letterCombinations(digits);
	for(unsigned int i = 0; i < result.size(); i++){
		cout << result[i] << endl;
	}
}
