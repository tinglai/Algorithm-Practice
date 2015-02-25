#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    bool canJump(int A[], int n){
		if(n == 0 || n == 1) return true; 
		vector<char> memo(n, 'u');
		return help(0, A[0], A, n);
    }
	bool help(int idx, int farestIdx, int A[], int n){
// farestIdx records the farest index from 0 we can go to
// and idx is the start point of the search
		int farest = 0;
		for(int i = idx; i <= farestIdx; i++){
			if(A[i] + i >= n - 1) return true;
			if(A[i] + i > farest) farest = A[i] + i;
		}
		if(farest == farestIdx) return false;
		else{
			return help(farestIdx + 1, farest, A, n);
		}
	}
};

int main(){
	//int A[] = {2,0,6,9,8,4,5,0,8,9,1,2,9,6,8,8,0,6,3,1,2,2,1,2,6,5,3,1,2,2,6,4,2,4,3,0,0,0,3,8,2,4,0,1,2,0,1,4,6,5,8,0,7,9,3,4,6,6,5,8,9,3,4,3,7,0,4,9,0,9,8,4,3,0,7,7,1,9,1,9,4,9,0,1,9,5,7,7,1,5,8,2,8,2,6,8,2,2,7,5,1,7,9,6};
	int A[] = {3,0,0,0,4};
	//int A[] = {2,3,1,1,4};
	int n = 5;
	Solution soln;
	bool result = soln.canJump(A, n);
	if(result) cout << "yes" << endl;
	else cout << "no" << endl;
}
