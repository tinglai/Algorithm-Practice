#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution{
public:
	int numDistinct(string s, string t){
		vector<int> memo1(s.size() + 1, 0);
		vector<int> memo2(s.size() + 1, 0);
		for(int i = 1; i <= t.size(); i++){
			memo2 = memo1;
			memo2[0] = 1;
			for(int j = 1; j <= s.size(); j++){
				if(j < i) memo1[j] = 0;
				else if(s[j - 1] == t[i - 1]){
					if(i == 1){
						memo1[j] = 1 + memo1[j - 1];
					}
					else memo1[j] = memo2[j - 1] + memo1[j - 1];
				}
				else{
					memo1[j] = memo1[j - 1];
				}
			}
		}
		return memo1.back();
	}
/*
	void help(string s, string t, int& result){
		if(s.length() < t.length()) return;
		if(t.length() == 0){
			result++;
			return;
		}
		if(s[0] != t[0]){
			help(s.substr(1), t, result);
		}
		else{
			help(s.substr(1), t.substr(1), result);
			help(s.substr(1), t, result);
		}
	}
*/
};

int main(){
	string s = "abcde";
	//string s = "rabbbit";
	string t = "ace";
	//string t = "rabbit";
	Solution soln;
	int result = soln.numDistinct(s, t);
	cout << "result = " << result << endl;
}
