#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    int maxSubArray(int A[], int n){
		if(n == 0) return 0;
		//vector<int> memo(n + 1);
		//memo[0] = 0;
		int memo = 0;
		int result = A[0];
		// record the max sum using A[i] as the last elem
		for(int i = 0; i < n; i++){
			if(memo < 0) memo = A[i];
			else memo = A[i] + memo;
			if(memo > result) result = memo;
		}
		return result;
    }
};

int main(){
	int A[] = {-2,1,-3,4,-1,2,1,-5,4};
	Solution soln;
	int result = soln.maxSubArray(A, 9);
	cout << "result = " << result << endl;
}
