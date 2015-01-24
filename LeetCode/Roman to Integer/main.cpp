#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int romanToInt(string s){
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
		int result = 0;
		int cur;
		int last = 0;
		int size = (int)s.size();
		for(int i = size - 1; i >= 0; i--){
			switch(s[i]){
				case 'I':
					cur = 1;
					break;
				case 'V':
					cur = 5;
					break;
				case 'X':
					cur = 10;
					break;
				case 'L':
					cur = 50;
					break;
				case 'C':
					cur = 100;
					break;
				case 'D':
					cur = 500;
					break;
				case 'M':
					cur = 1000;
					break;
				default:
					return -1;
			}
			if(cur >= last) result += cur;
			else result -= cur;
			last = cur;
		}
		return result;
    }
};

int main(){
	string s;
	cout << "s = "; cin >> s;
	Solution soln;
	int result = soln.romanToInt(s);
	cout << "result = " << result << endl;
}
