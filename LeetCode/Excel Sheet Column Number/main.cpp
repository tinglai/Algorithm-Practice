#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class Solution{
public:
    int titleToNumber(string s){
		int result = 0;
		if(s.empty()) return result;
		int size = (int)s.size();
		for(int i = size - 1; i >= 0; i--){
			int toAdd = (s[i] - 'A') + 1;
			result += toAdd * pow(26, size - 1 - i);
		}
		return result;
    }
};

int main(){
	string s;
	cout << "s = "; cin >> s;
	Solution soln;
	int result = soln.titleToNumber(s);
	cout << "result = " << result << endl;
}
