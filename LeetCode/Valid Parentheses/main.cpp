#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
		if(s.size() % 2 == 1) return false;
		if(s[0] != '(' && s[0] != '{' && s[0] != '[') return false;
		vector<char> stk;
		//this is a stack that only contains '(', '{', and '['
		stk.push_back(s[0]);
		for(unsigned int i = 1; i < s.length(); i++){
			if(s[i] == '(' || s[i] == '{' || s[i] == '['){
				stk.push_back(s[i]);
			}
			else{
				if(stk.empty()) return false;
				if(s[i] == ')' && stk.back() != '(') return false;
				else if(s[i] == '}' && stk.back() != '{') return false;
				else if(s[i] == ']' && stk.back() != '[') return false;
				else{
					stk.pop_back();
				}
			}
		}
		if(stk.empty()){
			return true;
		}
		else{
			return false;
		}
    }
};

int main(){
	string s;
	cout << "s = ";
	cin >> s;
	Solution soln;
	if(soln.isValid(s)){
		cout << "valid" << endl;
	}
	else{
		cout << "not valid" << endl;
	}
}
