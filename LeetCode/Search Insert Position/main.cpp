#include <iostream>

using namespace std;

class Solution{
public:
    int searchInsert(int A[], int n, int target){
		int result;
		result = help(A, 0, n - 1, n, target);
		return result;
    }
	int help(int A[], int a, int b, int n, int target){
		if(b - a <= 1){
			if(target <= A[a]) return a;
			if(target <= A[b])
				return b;
			else
				return b + 1;
		}
		int mid = (a + b) / 2;
		if(A[mid] == target) return mid; 
		if(target < A[mid]) return help(A, a, mid, n, target);
		else return help(A, mid, b, n, target);
	}
};

int main(){
	int A[] = {1, 3, 5, 6};
	int n = 4;
	int target;
	cout << "target = ";
	cin >> target;
	Solution soln;
	int result = soln.searchInsert(A, n, target);
	cout << "result = " << result << endl;
}
