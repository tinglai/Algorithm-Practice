#include <vector>
#include <iostream>
#include <string>

using namespace std;

class Solution{
public:
    int evalRPN(vector<string> &tokens){
		vector<int> stk;//simulate a stack
		int result;
		for(unsigned int i = 0; i < tokens.size(); i++){
			if(tokens[i] != "+" && tokens[i] != "-" &&
			   tokens[i] != "*" && tokens[i] != "/"){
				int in = stoi(tokens[i]);
				stk.push_back(in);
			}
			else{
				int temp1 = stk.back();
				stk.pop_back();
				int temp2 = stk.back();
				stk.pop_back();
				if(tokens[i] == "+"){
					result = temp2 + temp1;
					stk.push_back(result);
				}
				if(tokens[i] == "-"){
					result = temp2 - temp1;
					stk.push_back(result);
				}
				if(tokens[i] == "*"){
					result = temp2 * temp1;
					stk.push_back(result);
				}
				if(tokens[i] == "/"){
					result = temp2 / temp1;
					stk.push_back(result);
				}
			}
		}
		return stk[0];
    }
};

int main(){
	//vector<string> tokens = {"2", "1", "+", "3", "*"};
	vector<string> tokens = {"4", "13", "5", "/", "+"};
	Solution soln;
	int result = soln.evalRPN(tokens);
	cout << "result = " << result << endl;
}
