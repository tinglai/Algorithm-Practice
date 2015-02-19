#include <iostream>
#include <string>
#include <vector>


using namespace std;

class Solution{
public:
    vector<string> generateParenthesis(int n){
		vector<string> result;
		string tempRes;
		help(result, n, n, tempRes);
		return result;
    }
	void help(vector<string>& result, int left, int right, string& tempRes){
		if(left == 0 && right == 0){
			result.push_back(tempRes);
			return;
		}

		if(left < 0) return;

		if(left == right){
			string temp = tempRes;
			temp.push_back('(');
			help(result, left - 1, right, temp);
		}
		else{
			string temp = tempRes;
			temp.push_back('(');
			help(result, left - 1, right, temp);
			tempRes.push_back(')');
			help(result, left, right - 1, tempRes);
		}
	}
};

int main(){
	int n;
	cout << "n = "; cin >> n;
	Solution soln;
	vector<string> result = soln.generateParenthesis(n);
	for(unsigned int i = 0; i < result.size(); i++){
		cout << result[i] << endl;
	}
}
