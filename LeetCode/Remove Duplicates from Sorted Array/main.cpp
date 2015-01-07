#include <iostream>

using namespace std;

class Solution {
public:
    int removeDuplicates(int A[], int n){
		if(n <= 0) return n;
		
		int i = 1;
		int result = 0;
		while(i < n){
			if(A[i] == A[result]){
				i++;
			}
			else{
				if(i - result == 1){
					i++;
					result++;
				}
				else{
					A[++result] = A[i];
					i++;
				}
			}
		}
		return result + 1;
    }
};

int main(){
	int A[] = {1, 1, 2, 2, 3, 3, 3};
	Solution soln;
	int n = 7;
	int result = soln.removeDuplicates(A, n);
	cout << "result = " << result << endl;
	for(int i = 0; i < result; i++){
		cout << A[i] << ' ';
	}
	cout << endl;
}
