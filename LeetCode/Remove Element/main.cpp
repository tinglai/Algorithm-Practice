#include <iostream>

using namespace std;

class Solution{
public:
    int removeElement(int A[], int n, int elem){
		if(n == 0) return 0;
		int result = n;
		int i = 0;
		int j = 0;
		for(; i < n; i++){
			if(A[i] != elem){
				A[j] = A[i];
				j++;
			}
			else{
				result--;
				continue;
			}
		}
		return result;
    }
};

int main(){
	int A[] = {1,1,1,1,1,1,1,1,1,1};
	int n = 10;
	int elem = 1;
	Solution soln;
	int result = soln.removeElement(A, n, elem);
	cout << "result = " << result << endl;
	for(int i = 0; i < result; i++){
		cout << A[i] << " ";
	}
	cout << endl;
}
