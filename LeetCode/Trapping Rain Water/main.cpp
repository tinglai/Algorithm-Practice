#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Solution{
public:
    int trap(int A[], int n){
		if(n <= 1) return 0;

		vector<int> forward(n, 0);
		vector<int> backward(n, 0);

		int result = 0;

		int curHighest = A[0];
		for(int i = 1; i < n - 1; i++){
			if(A[i] > curHighest){
				curHighest = A[i];
			}
			else{
				forward[i] = curHighest - A[i];
			}
		}
		curHighest = A[n - 1];
		for(int i = n - 2; i > 0; i--){
			if(A[i] > curHighest){
				curHighest = A[i];
			}
			else{
				backward[i] = curHighest - A[i];
			}
		}
		for(int i = 0; i < n; i++){
			result += min(forward[i], backward[i]);
		}

		return result;
	}
};

int main(){
	int A[] = {1,1,1,2,1,1,1,1,2,1,2,1};
	int n = 12;
	Solution soln;
	int result = soln.trap(A, n);
	cout << "result = " << result << endl;
}
