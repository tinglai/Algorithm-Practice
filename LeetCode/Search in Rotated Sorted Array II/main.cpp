#include <iostream>

using namespace std;

class Solution{
public:
    bool search(int A[], int n, int target){
		if(n == 0) return false;
		if(n == 1) return target == A[0];
		if(A[0] < A[n - 1]) return binarySearch(A, 0, n - 1, target);
		else if(A[0] > A[n - 1]) return help(A, 0, n - 1, target);
		else{
			int i = 1;
			int last = A[0];
			for(; i < n; i++){
				if(A[i] != last) break;
			}
			if(i == n) return target == last;
			else if(A[i] > last) return help(A, i, n - 1, target);
			else return binarySearch(A, i, n - 1, target);
		}
    }
	bool help(int A[], int a, int b, int target){
		int mid = (a + b) / 2;
		if(a > b) return false;
		if(a == b) return target == A[mid];
		if(target == A[mid]) return true;
		if(A[mid] >= A[a]){
			if(target < A[mid] && target >= A[a]) return binarySearch(A, a, mid - 1, target);
			else return help(A, mid + 1, b, target);
		}
		else{
			if(target > A[mid] && target <= A[b]) return binarySearch(A, mid + 1, b, target);
			else return help(A, a, mid - 1, target);
		}
	}
	bool binarySearch(int A[], int a, int b, int target){
		int mid = (a + b) / 2;
		if(a > b) return false;
		if(a == b) return A[mid] == target;
		else{
			if(A[mid] == target) return true;
			if(A[mid] > target) return binarySearch(A, a, mid - 1, target);
			else return binarySearch(A, mid + 1, b, target);
		}
	}
};

int main(){
	int A[] = {1, 3};
	//int A[] = {5,5,5,6,7,1,2,2,3,3,4,5};
	int n = 2;
	int target = 0;
	Solution soln;
	bool result = soln.search(A, n, target);
	if(result) cout << "found target" << endl;
	else cout << "could not find target" << endl;
}
