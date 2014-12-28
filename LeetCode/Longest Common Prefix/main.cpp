#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
		unsigned int j = 0;
		string result;
		if(strs.empty()) return result;
		while(j < strs[0].size()){
			char temp = strs[0][j];
			for(unsigned int i = 1; i < strs.size(); i++){
				if(j >= strs[i].length()) return result;
				if(temp != strs[i][j]) return result;
			}
			result.push_back(temp);
			j++;
		}
		return result;
    }
};

int main(){
	vector<string> strs = {"abcd", "abc", "abce"};
	Solution soln;
	string result = soln.longestCommonPrefix(strs);
	cout << "the longest common prefix among the strings is " << result << endl;
}
