#include <iostream>
#include <cmath>

using namespace std;

class Solution{
public:
    int trailingZeroes(int n){
//the trick here is: how many 5^k, k = 1, 2, 3, 4, ...
//does n contain. for each 5^k, it will generate k trailing
//zeroes since it can be taken as product of k 5s
		int result = 0;
		if(n == 0) return 0;
		int a = log(n) / log(5);
		int digit = pow(5, a);
		int count = n / digit;
		int total = count;
		result += count * a;
		a--;
		while(a > 0){
			digit = pow(5, a);
			count = n / digit - total;
			total += count;
			result += count * a;
			a--;
		}
		return result;
    }
};

int main(){
	int n;
	cout << "n = "; cin >> n;
	Solution soln;
	int result = soln.trailingZeroes(n);
	cout << "result = " << result << endl;
}
