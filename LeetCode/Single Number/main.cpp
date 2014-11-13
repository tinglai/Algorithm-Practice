#include <iostream>

using namespace std;

class Solution {
public:
    int singleNumber(int A[], int n) {
		int result = 0;
		for(int i = 0; i < n; i++){
			result = result ^ A[i];
			//using XOR to add all the int together 
			//then the remaining result will be the single int
		}
		return result;
    }
};

int main(){
	int A[] = {1,2,3,4,3,2,1};
	int n = 7;
	Solution solt;
	int result = solt.singleNumber(A, n);
	cout << result << endl;
}
