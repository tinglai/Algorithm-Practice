#include <iostream>
#include <cmath>

using namespace std;

class Solution{
//the main idea is not multiply each x linearly but let
//result * result everytime to get O(log(n)) in time
public:
/*
    double pow(double x, int n){
		if(x == 0) return 0;
		if(x == 1) return 1;
		int sign = 1;
		if(x < 0){
			sign = (n % 2 == 0? 1: -1);
			x = -x;
		}
		if(n == 0) return 1;
		if(n == 1) return x;
		if(n < 0) return 1 / pow(x, -n);
		return pow(x * x, n / 2) * pow(x, n % 2) * sign;
    }
*/
//above is written in tail recursion
//following is written in iteration
    double pow(double x, int n){
		if(x == 0) return 0;
		if(x == 1) return 1;
		int sign = 1;
		if(x < 0){
			sign = (n % 2 == 0? 1: -1);
			x = -x;
		}
		if(n == 0) return 1;
		if(n == 1) return x;

		double result = 1;
		int countN = abs(n);
		int remainN = countN;
		while(remainN > 0){
			int i = 1;
			double curRes = x;
			while(1){
				if(2 * i <= countN){
					curRes = curRes * curRes;
				}
				else break;
				i = 2 * i;
			}
			remainN -= i;
			result *= curRes;
		}
		if(n > 0) return sign * result;
		else return sign / result;
    }
};

int main(){
	double x;
	int n;
	cout << "x = "; cin >> x;
	cout << "n = "; cin >> n;
	Solution soln;
	double result = soln.pow(x, n);
	cout << "result = " << result << endl;
}
