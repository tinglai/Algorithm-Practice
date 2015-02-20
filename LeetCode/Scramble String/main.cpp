#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution{
public:
    bool isScramble(string s1, string s2){
		return help2(s1, s2);
    }
// can use index to check the validility instead of using substring
// which is much slower
	bool help(string& s1, string& s2){
		if(s1.empty() && s2.empty()) return true;
		int size1 = (int)s1.size();
		int size2 = (int)s2.size();
		if(size1 != size2) return false;
		if(size1 == 1 && size2 == 1) return s1 == s2;
		if(!help2(s1, s2)) return false;

		for(int i = 1; i < size1; i++){
			string temp11 = s1.substr(0, i);
			string temp12 = s1.substr(i);
			string temp21 = s2.substr(0, i);
			string temp22 = s2.substr(i);
			if(help(temp11, temp21) && help(temp12, temp22)) return true;
		}
		for(int i = 1; i < size1; i++){
			string temp11 = s1.substr(0, i);
			string temp12 = s1.substr(i);
			string temp21 = s2.substr(size1 - i);
			string temp22 = s2.substr(0, size1 - i);
			if(help(temp11, temp21) && help(temp12, temp22)) return true;
		}
		return false;
	}
	bool help2(string& s1, string& s2){
	// determin if s1 and s2 are palindrome
		if(s1.size() != s2.size()) return false;
		unordered_map<char, int> s1Count, s2Count;
		for(unsigned int i = 0; i < s1.size(); i++){
			s1Count[s1[i]]++;
			s2Count[s2[i]]++;
		}
		for(unordered_map<char, int>::iterator i = s1Count.begin(); 
			   i != s1Count.end(); i++){
			if(i->second != s2Count[i->first]) return false;
		}
		return true;
	}
};

int main(){
	string s1, s2;
	s1 = "aabb";
	s2 = "abab";
	Solution soln;
	bool result = soln.isScramble(s1, s2);
	if(result) cout << "true" << endl;
	else cout << "false" << endl;
}
