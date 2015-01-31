#include <iostream>

using namespace std;

class Solution{
public:
    void merge(int A[], int m, int B[], int n){
		if(n == 0) return;
		int itrA = m - 1;
		int itrB = n - 1;
		int i = m + n - 1;
		for(; i >= 0; i--){
			if(itrA < 0) break;
			if(itrB < 0) break;
			if(A[itrA] > B[itrB]){
				A[i] = A[itrA];
				itrA--;
			}
			else{
				A[i] = B[itrB];
				itrB--;
			}
		}

		if(itrA >= 0){
			return;
		}
		if(itrB >= 0){
			while(i >= 0){
				A[i] = B[itrB];
				i--;
				itrB--;
			}
		}
    }
};

int main(){
	int A[12] = {1, 3, 5, 6, 7, 8, 10};
	int B[5] = {3, 5, 7, 8, 12};
	int m = 7, n = 5;
	Solution soln;
	soln.merge(A, m, B, n);
	for(int i = 0; i < m + n; i++){
		cout << A[i] << " ";
	}
	cout << endl;
}
