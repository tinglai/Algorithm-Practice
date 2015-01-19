#include <iostream>
#include <string>

using namespace std;

class Solution{
public:
    string longestPalindrome(string s){
		if(s.size() <= 1) return s;
		string result;
		if(s[0] == s[1]) result = s.substr(0, 2);
		else result = s.substr(0, 1);
		for(unsigned int i = 2; i < s.size(); i++){
			if(result.size() == i){
				string tempStr = s.substr(0, i + 1);
				if(isPalindrome(tempStr)) result = tempStr;
			}
			else{
				string tempStr1 = s.substr(i - result.size() - 1, result.size() + 2);
				if(isPalindrome(tempStr1)) result = tempStr1;
				else{
					string tempStr2 = s.substr(i - result.size(), result.size() + 1);
					if(isPalindrome(tempStr2)) result = tempStr2;
				}
			}
		}
		return result;
    }
	bool isPalindrome(string& s){
		if(s.size() <= 0) return true;
		unsigned int halfLength = s.size() / 2;
		unsigned int n = s.size();
		for(unsigned int i = 0; i < halfLength; i++){
			if(s[i] != s[n - 1 - i]) return false;
		}
		return true;
	}
};

int main(){
	string s;
	cout << "s = ";
	cin >> s;
	Solution soln;
	string result = soln.longestPalindrome(s);
	cout << "result = " << result << endl;
}
