#include <iostream>

using namespace std;

class Solution {
public:
    int sqrt(int x) {
		if(x < 0) exit(1);
		if(x == 0) return 0;
		long oldResult = 1;
		long result = 1;
		while(true){
			oldResult = result;
			result = oldResult - (x - oldResult * oldResult) / (-2 * oldResult);
			if(result == oldResult){
				break;
			}
		}
		long diff= x - result * result;
		if(diff >= 0) return (int)result;
		else return (int)result - 1;
    }
};

int main(){
	int x;
	cout << "x = "; 
	cin >> x;
	Solution sol;
	cout << "sqrt of x is " << sol.sqrt(x) << endl;
}
