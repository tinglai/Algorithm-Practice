#include <iostream>

using namespace std;

class Solution{
public:
    int search(int A[], int n, int target){
		if(n <= 0) return -1;
		int result;
		result = help(A, 0, n - 1, target);
		return result;
    }
	int help(int A[], int a, int b, int target){
		if(b < a) return -1;
		if(b == a){
			if(A[a] == target) return a;
			else return -1;
		}
		int mid = (a + b) / 2;
		if(A[mid] == target) return mid;
		if(A[mid] < A[b]){
		//in this case, A[mid] ~ A[b] is sorted
			if(target > A[mid] && target <= A[b])
				return binarySearch(A, mid + 1, b, target);
			else return help(A, a, mid - 1, target);
		}
		else{
		//in this case, A[a] ~ A[mid] is sorted
			if(target < A[mid] && target >= A[a])
				return binarySearch(A, a, mid - 1, target);
			else return help(A, mid + 1, b, target);
		}
	}
	int binarySearch(int A[], int a, int b, int target){
		if(b < a) return -1;
		if(b == a){
			if(A[a] == target) return a;
			else return -1;
		}
		
		int mid = (a + b) / 2;
		if(A[mid] == target) return mid;
		if(A[mid] > target) return binarySearch(A, a, mid - 1, target);
		else return binarySearch(A, mid + 1, b, target);
	}
};

int main(){
	int A[] = {4, 5, 6, 7, 0, 1, 2};
	int n = 7;
	int target;
	cout << "target = ";
	cin >> target;
	Solution soln;
	int result = soln.search(A, n, target);
	cout << "result = " << result << endl;
}
