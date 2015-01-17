#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <string>

using namespace std;

class Solution {
public:
    bool wordBreak(string s, unordered_set<string> &dict){
		//if(s.size() == 0) return true;
		unordered_map<string, bool> memo;
		return help(s, dict, memo);
    }

	bool help(string s, unordered_set<string>& dict, 
			     unordered_map<string, bool>& memo){

		if(memo.count(s) != 0) return memo[s];

		if(s.size() == 0) return true;
		int length = (int)s.size();
		for(int i = 1; i <= length; i++){
		//here assume in dict, there are no words with length = 0
		//since in the wordBreak func, I've dealed with the case
		//in which dict is empty
			string tempStr = s.substr(0, i);
			if(dict.count(tempStr) != 0){
				bool result = help(s.substr(i), dict, memo);
				memo.emplace(s.substr(i), result);
				if(result){
					return true;
				}
			}
		}
		memo.emplace(s, false);
		return false;
	}
};

int main(){
	string s;
	cout << "s = ";
	cin >> s;
	
	unordered_set<string> dict = {"a", "b", "c", "d"};
	//unordered_set<string> dict;
	
	Solution soln;
	bool result = soln.wordBreak(s, dict);
	if(result){
		cout << "true" << endl;
	}
	else{
		cout << "false" << endl;
	}
}
