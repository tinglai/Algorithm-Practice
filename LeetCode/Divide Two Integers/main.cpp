#include <iostream>
#include <climits>
#include <string>

using namespace std;

class Solution{
public:
    int divide(long dividend, long divisor){
		if(divisor == 0) return INT_MAX;
		if(dividend == 0) return 0;
		bool sign = true;//if sign is positive
		if((dividend < 0 && divisor > 0) || (dividend > 0 && divisor < 0)){
			sign = false;
		}
		if(dividend < 0) dividend = 0 - dividend;
		if(divisor < 0) divisor = 0 - divisor;
		string dividendStr = to_string(dividend);
		string resultStr;
		string toPush;
		unsigned int j = 0;
		long temp = 0;
		while(j < dividendStr.size()){
			string tempStr = to_string(temp);
			//string substring= dividendStr.substr(i, j - i + 1);
			string substring = dividendStr.substr(j, 1);
			tempStr += substring;
			temp = stol(tempStr);
			if(temp < divisor){
				if(!resultStr.empty()){
					toPush.push_back('0');
				}
				j++;
			}
			else{
				int count = 0;
				while(1){
					temp -= divisor;
					if(temp >= 0) count++;
					else break;
				}
				toPush += to_string(count);
				resultStr += toPush;
				toPush = "";
				temp = temp + divisor;
				//if(temp == 0) dividendStr = dividendStr.substr(j + 1);
				//else dividendStr = to_string(temp) + dividendStr.substr(j + 1);
				j++;
			}
		}
		if(!toPush.empty()) resultStr += toPush;
		int result;
		//resultStr.pop_back();
		if(resultStr.empty()) result = 0;
		else{
			if(sign){
				if(resultStr.size() < 10) result = stoi(resultStr);
				else if(resultStr.size() > 10) return INT_MAX;
				else if(resultStr[0] > '2') return INT_MAX;
				else if(resultStr[0] == '2' && resultStr[1] > '1') return INT_MAX;
				else if(resultStr[1] == '1' && resultStr[2] > '4') return INT_MAX;
				else if(resultStr[2] == '4' && resultStr[3] > '7') return INT_MAX;
				else if(resultStr[3] == '7' && resultStr[4] > '4') return INT_MAX;
				else if(resultStr[4] == '4' && resultStr[5] > '8') return INT_MAX;
				else if(resultStr[5] == '8' && resultStr[6] > '3') return INT_MAX;
				else if(resultStr[6] == '3' && resultStr[7] > '6') return INT_MAX;
				else if(resultStr[7] == '6' && resultStr[8] > '4') return INT_MAX;
				else if(resultStr[8] == '4' && resultStr[9] > '7') return INT_MAX;
				else result = stoi(resultStr);
			}
			else{
				if(resultStr.size() < 10) result = stoi(resultStr);
				else if(resultStr[0] > '2') return INT_MAX;
				else if(resultStr[0] == '2' && resultStr[1] > '1') return INT_MAX;
				else if(resultStr[1] == '1' && resultStr[2] > '4') return INT_MAX;
				else if(resultStr[2] == '4' && resultStr[3] > '7') return INT_MAX;
				else if(resultStr[3] == '7' && resultStr[4] > '4') return INT_MAX;
				else if(resultStr[4] == '4' && resultStr[5] > '8') return INT_MAX;
				else if(resultStr[5] == '8' && resultStr[6] > '3') return INT_MAX;
				else if(resultStr[6] == '3' && resultStr[7] > '6') return INT_MAX;
				else if(resultStr[7] == '6' && resultStr[8] > '4') return INT_MAX;
				else if(resultStr[8] == '4' && resultStr[9] > '8') return INT_MAX;
				else{
					long tempResult = stol(resultStr);
					result = 0 - tempResult;
					return result;
				}
			}
		}
		if(!sign) result = 0 - result;
		return result;
	}
};

int main(){
	//int dividend;
	int dividend = -1060849722;
	//int divisor = -1017100424;
	//int divisor;
	int divisor = 99958928;
	//cout << "dividend = "; cin >> dividend;
	//cout << "divisor = "; cin >> divisor;
	Solution soln;
	int result = soln.divide(dividend, divisor);
	cout << "result = " << result << endl;
}
