#include <iostream>
#include <climits>
#include <cmath>

using namespace std;

class Solution{
public:
    bool isPalindrome(int x){
		if(x < 0){
			return false;
/*
			if(x == INT_MIN) return false;
			else x = -x;
*/
		}
		int n = log(x) / log(10);
		while(n > 0){
			int a = pow(10, n);
			int b1 = x % 10;
			int b2 = x / a;
cout << "a = " << a << endl;
cout << "b1 = " << b1 << " b2 = " << b2 << endl;
			if(b1 != b2) return false;
			x = (x - a * b2) / 10;
cout << "x = " << x << endl;
			n = log(x) / log(10);
cout << "n = " << endl;
		}
		return true;
    }
};

int main(){
	int x;
	cout << "x = "; cin >> x;
	Solution soln;
	bool result = soln.isPalindrome(x);
	if(result) cout << "Yes, it's palindrome" << endl;
	else cout << "No, it is not palindrome" << endl;
}
