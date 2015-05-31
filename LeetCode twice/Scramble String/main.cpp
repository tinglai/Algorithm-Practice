#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

class Solution {
public:
	bool isScramble(string s1, string s2){
		return help(s1, s2);
	}
	bool help(string& s1, string& s2){
		if(s1 == s2) return true;
		if(s1.size() != s2.size()) return false;
		if(s1.size() == 1) return false;
		if(s1.size() == 2){
			if(s1[0] == s2[1] && s1[1] == s2[0]) return true;
			else return false;
		}
		unordered_map<char, int> wordCount;
		for(unsigned int i = 0; i < s1.size(); i++){
			if(wordCount.count(s1[i]) == 0){
				wordCount.emplace(s1[i], 1);
			}
			else wordCount[s1[i]]++;
		}
		for(unsigned int i = 0; i < s1.size(); i++){
			if(wordCount.count(s2[i]) == 0 || wordCount[s2[i]] == 0){
				return false;
			}
			else{
				wordCount[s2[i]]--;
			}
		}
		
		for(unsigned int i = 1; i < s1.size(); i++){
			string s11 = s1.substr(0, i);
			string s12 = s1.substr(i);
			string s21 = s2.substr(0, i);
			string s22 = s2.substr(i);
			if(help(s11, s21) && help(s12, s22)) return true;
		}

		for(unsigned int i = 1; i < s1.size(); i++){
			string s11 = s1.substr(0, i);
			string s12 = s1.substr(i);
			string s21 = s2.substr(s1.size() - i, i);
			string s22 = s2.substr(0, s1.size() - i);
			if(help(s11, s21) && help(s12, s22)) return true;
		}
		return false;
	}
};

int main(){
	string s1 = "abc";
	string s2 = "bac";

	Solution soln;
	bool result = soln.isScramble(s1, s2);
	if(result) cout << "yes" << endl;
	else cout << "no" << endl;
}
