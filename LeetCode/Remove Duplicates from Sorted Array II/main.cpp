#include <iostream>

using namespace std;

class Solution{
public:
    int removeDuplicates(int A[], int n){
		if(n <= 1) return n;
		int count = 1;
		int result = 1;
		int fast = 1;
		int slow = 1;
		while(fast < n){
			if(A[fast] == A[fast - 1]){
				if(count == 2){
					fast++;
				}
				else{
					count++;
					A[slow] = A[fast];
					slow++;
					fast++;
					result++;
				}
			}
			else{
				count = 1;
				A[slow] = A[fast];
				slow++;
				fast++;
				result++;
			}
		}
		return result;
    }
};

int main(){
	int A[] = {1, 1, 2, 2, 3};
	int n = 5;
	Solution soln;
	int result = soln.removeDuplicates(A, n);
	cout << "result = " << result << endl;
}
