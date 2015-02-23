#include <iostream>
#include <vector>
#include <string>

using namespace std;

// ()(((()
// (()(((()
// )()())()()(
class Solution{
public:
    int longestValidParentheses(string s){
		if(s.empty()) return 0;

		int result = 0;
		vector<int> leftParenthese;
		vector<int> waitForMerge;

		for(unsigned int i = 0; i < s.size(); i++){
			if(s[i] == '('){
				if(leftParenthese.empty() || s[i - 1] == ')'){
					leftParenthese.push_back(1);
					waitForMerge.push_back(0);
				}
				else{
					leftParenthese.back()++;
				}
			}
			else{
				if(leftParenthese.empty()){
					for(unsigned int i = 0; i < waitForMerge.size(); i++){
						if(waitForMerge[i] > result) result = waitForMerge[i];
					}
					waitForMerge.clear();
				}

				else{
					leftParenthese.back()--;
					waitForMerge.back()++;
					if(leftParenthese.back() == 0){
						leftParenthese.pop_back();
						if(waitForMerge.size() > 1){
							int temp = waitForMerge.back();
							waitForMerge.pop_back();
							waitForMerge.back() += temp;
						}
					}
				}
			}

		}
		for(unsigned int i = 0; i < waitForMerge.size(); i++){
			if(waitForMerge[i] > result) result = waitForMerge[i];
		}
		return result * 2;
    }
};

int main(){
	string s = "(()(((()";
	//cout << "s = "; cin >> s;
	Solution soln;
	int result = soln.longestValidParentheses(s);
	cout << "result = " << result << endl;
}

/*
cout << "i = " << i << endl;
cout << "*** waitForMerge ***" << endl;
for(unsigned int j = 0; j < waitForMerge.size(); j++){
	cout << waitForMerge[j] << ' ';
}
cout << endl << "*** leftParenthese ***" << endl;
for(unsigned int j = 0; j < leftParenthese.size(); j++){
	cout << leftParenthese[j] << ' ';
}
cout << endl;
cout << endl;
*/
