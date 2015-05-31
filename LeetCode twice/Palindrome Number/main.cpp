#include <iostream>
#include <algorithm>

using namespace std;

class Solution{
public:
	bool isPalindrome(int x){
		int digitNum = 0;
		int temp = x;
		if(temp < 0) return false; // assume negative ints not palindrome
		if(temp < 10) return true;
		while(temp > 0){
			digitNum++;
			temp = temp / 10;
		}
		int a;
		int ttt = pow(10, digitNum / 2);
		a = x % ttt;
		int b = 0;
		temp = x;
		temp = temp / pow(10, digitNum / 2 + digitNum % 2);
		for(int i = 0; i < digitNum / 2; i++){
			b = b * 10 + temp % 10;
			temp = temp / 10;
		}
		return a == b;
	}
};

int main(){
	int x = 100;
	Solution soln;
	bool result = soln.isPalindrome(x);
	if(result) cout << "yes" << endl;
	else cout << "no" << endl;
}
