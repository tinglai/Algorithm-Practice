#include <iostream>

using namespace std;

class Solution{
public:
    int singleNumber(int A[], int n){
		int bit1 = 0;
		int bit2 = 0;
		for(int i = 0; i < n; i++){
			int temp = bit1;
			bit1 = ~((~bit1) ^ (bit2 & A[i]));
			bit2 = ~((~bit2) ^ ((~(temp ^ bit2)) & A[i]));
		}
		return bit2;
    }
};
//one important fact is as following:
//for two bools, x, y. to replicate the relation that
//x will change if y == 1, and x will stay if y == 0
//we can do as follows,
//    x = ~((~x) ^ y)
//    check:
//    x = 0, y = 1, x = ~((~0) ^ 1) = 1
//    x = 1, y = 1, x = ~((~1) ^ 1) = 0
//    x = 0, y = 0, x = ~((~0) ^ 0) = 0
//    x = 1, y = 0, x = ~((~1) ^ 0) = 1

int main(){
	int A[] = {1, 1, 1, 3, 5, 5, 4, 4, 4, 5};
	//int A[] = {1, 3, 1, 3, 6, 6, 4, 4, 5};
	int n = 10;
	Solution soln;
	int result = soln.singleNumber(A, n);
	cout << "result = " << result << endl;
}
