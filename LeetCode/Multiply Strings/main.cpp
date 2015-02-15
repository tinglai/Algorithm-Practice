#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution{
public:
    string multiply(string num1, string num2){
		int sign = 1;
		if(num1[0] == '-'){
			sign = -1 * sign;
			num1 = num1.substr(1);
		}
		if(num2[0] == '-'){
			sign = -1 * sign;
			num2 = num2.substr(1);
		}
		if(num1 == "0" || num2 == "0") return "0";
		if(num1 == "1") return num2;
		if(num2 == "1") return num1;

		int N = (int)num2.size();
		vector<int> resultInt;
		for(int i = N - 1; i >= 0; i--){
			vector<int> tempRes;
			help(num1, (int)(num2[i] - '0'), N - 1 - i, tempRes);
			help2(resultInt, tempRes);

		}
		string result;
		if(sign == -1) result.push_back('-');
		for(int i = (int)resultInt.size() - 1; i >= 0; i--){
			result.push_back((char)(resultInt[i] + '0'));
		}
		return result;
    }
	void help(string& num1, int digit, int NumZeros, vector<int>& result){
// multiply num1 with each digit on num2
// and save the result in result
		if(digit == 0) return;
		for(int i = 0; i < NumZeros; i++){
			result.push_back(0);
		}
		int add = 0;
		for(int i = (int)num1.size() - 1; i >= 0; i--){
			int multi_res = (int)(num1[i] - '0') * digit;
			int toPush = add + multi_res;
			add = toPush / 10;
			toPush = toPush % 10;
			result.push_back(toPush);
		}
		if(add > 0){
			result.push_back(add);
		}
	}
	void help2(vector<int>& resultInt, vector<int>& tempRes){
		if(tempRes.empty()) return;
		int add = 0;
		unsigned int i = 0;
		for(; i < min(resultInt.size(), tempRes.size()); i++){
			int toPush = resultInt[i] + tempRes[i] + add;
			add = toPush / 10;
			toPush = toPush % 10;
			resultInt[i] = toPush;
		}
		if(resultInt.size() > tempRes.size()){
			for(; i < resultInt.size(); i++){
				resultInt[i] = add + resultInt[i];
				add = resultInt[i] / 10;
				resultInt[i] = resultInt[i] % 10;
			}
			if(add > 0) resultInt.push_back(add);
		}
		else{
			for(; i < tempRes.size(); i++){
				int toPush = tempRes[i] + add;
				add = toPush / 10;
				toPush = toPush % 10;
				resultInt.push_back(toPush);
			}
			if(add > 0) resultInt.push_back(add);
		}
	}
};

int main(){
	string num1, num2;
	cout << "num1 = "; cin >> num1;
	cout << "num2 = "; cin >> num2;
	Solution soln;
	string result = soln.multiply(num1, num2);
	cout << "result = " << result << endl;
}
