#include <iostream>
#include <string>

using namespace std;

/*
        Symbol 	Value
			I 	1
			V 	5
			X 	10
			L 	50
			C 	100
			D 	500
			M 	1,000
*/

class Solution{
public:
    string intToRoman(int num){
		string result;

		int a = num / 1000;
		for(int i = 0; i < a; i++){
			result.push_back('M');
		}
		num = num - a * 1000;

		help(result, 100, num, 'D', 'C', 'M');
		help(result, 10, num, 'L', 'X', 'C');
		help(result, 1, num, 'V', 'I', 'X');

		return result;
    }

	void help(string& result, int digit, int &num, char five, char one, char ten){
//the key point here: to generate integer for every digit smaller than 1000
//since all 0 ~ 9 can be dealed with three chars, one, five, and ten
		int a = num / digit;
		num = num - a * digit;
		if(a == 0) return;
		if(a <= 3){
			for(int i = 0; i < a; i++){
				result.push_back(one);
			}
			return;
		}
		if(a <= 4){
			result.push_back(one);
			result.push_back(five);
			return;
		}
		if(a == 5){
			result.push_back(five);
			return;
		}
		if(a <= 8){
			result.push_back(five);
			for(int i = 0; i < a - 5; i++){
				result.push_back(one);
			}
			return;
		}
		if(a <= 9){
			result.push_back(one);
			result.push_back(ten);
			return;
		}
	}
};

int main(){
	int num;
	cout << "num = "; cin >> num;
	Solution soln;
	string result = soln.intToRoman(num);
	cout << "result = " << result << endl;
}
