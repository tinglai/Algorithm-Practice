#include <iostream>
#include <vector>
#include <string>

using namespace std;

// ()(((()
// (()(((()
class Solution{
public:
    int longestValidParentheses(string s){
		if(s.empty()) return 0;
		int result = 0;
		int count = 0;
		int tempCount = 0;
		vector<int> mountain;
		vector<int> waitForMerge
		for(unsigned int i = 0; i < s.size(); i++){
			if(s[i] == '('){
				if(mountain.empty()){
					mountain.push_back(1);
				}
			}
			else{
				if(mountain.empty()) continue;
				mountain.back()--;
				if(waitForMerge.empty()){
					waitForMerge.push(1);
				}
				else{
					waitForMerge.back()++;
				}
			}
		}
		if(count > result) result = count;
		if(tempCount > result) result = tempCount;
		return result * 2;
    }
};

int main(){
	string s;
	cout << "s = "; cin >> s;
	Solution soln;
	int result = soln.longestValidParentheses(s);
	cout << "result = " << result << endl;
}
