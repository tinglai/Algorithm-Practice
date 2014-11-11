#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
		if(s1.length() + s2.length() != s3.length()){
			return false;
		}
		vector<vector<char>> check(s1.length(), vector<char>(s2.length(), 'u'));
		//check vector is used to store if the substring of s3 
		//from end to front is interleaving form of substrings 
		//of the same form of s1 and s2
		//there are in total s1.length * s2.length combinations
		return help(s1, s2, s3, check);
    }

	bool help(string s1, string s2, string s3, vector<vector<char>>& check){
		//here assume s1.length + s2.length == s3.length since this 
		//has been checked by the previous function
		if(s1.length() == 0){
			return s2 == s3;
		}
		if(s2.length() == 0){
			return s1 == s3;
		}
		if(check[s1.length() - 1][s2.length() - 1] == 't') return true;
		else if(check[s1.length() - 1][s2.length() - 1] == 'f') return false;
		else{
			bool temp;
			if(s1[0] != s2[0]){
				if(s3[0] == s1[0]){
					temp = help(s1.substr(1), s2, s3.substr(1), check);
				}
				else if(s3[0] == s2[0]){
					temp = help(s1, s2.substr(1), s3.substr(1), check);
				}
				else{
					return false;
				}
			}
			else{
				if(s1[0] == s3[0]){
					temp = (help(s1.substr(1), s2, s3.substr(1), check) || 
							   help(s1, s2.substr(1), s3.substr(1), check));
				}
				else{
					return false;
				}
			}
			if(temp == true){
				check[s1.length() - 1][s2.length() - 1] = 't';
				return true;
			}
			else{
				check[s1.length() - 1][s2.length() - 1] = 'f';
				return false;
			}
		}
	}
};

int main(){
	string s1 = "abc";
	string s2 = "axa";
	string s3 = "aabaac";
	Solution solt;
	bool result = solt.isInterleave(s1, s2, s3);
	if(result){
		cout << "s3 is interleaving form of s1 and s2" << endl;
	}
	else{
		cout << "s3 is not interleaving form of s1 and s2" << endl;
	}
}
