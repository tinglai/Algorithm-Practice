#include <iostream>
#include <climits>
#include <cmath>

using namespace std;

class Solution{
public:
    bool isPalindrome(int x){
		if(x < 0){
			return false;
		}
		int x_temp = x;
		int y = 0;
		while(x_temp > 0){
			y = y * 10 + x_temp % 10;
			x_temp = x_temp / 10;
		}
		return (x - y == 0);
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
