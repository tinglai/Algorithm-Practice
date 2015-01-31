#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    void sortColors(int A[], int n){
		int red = 0, white = 0, blue = 0;
		for(int i = 0; i < n; i++){
			if(A[i] == 0) red++;
			else if(A[i] == 1) white++;
			else blue++;
		}
		int i = 0;
		for(; i < red; i++){
			A[i] = 0;
		}
		for(; i < white + red; i++){
			A[i] = 1;
		}
		for(; i < n; i++){
			A[i] = 2;
		}
    }
};

int main(){
	int A[] = {1,1,2,2,1,1,0,0,2};
	int n = 9;
	Solution soln;
	soln.sortColors(A, n);
	for(int i = 0; i < n; i++){
		cout << A[i] << " ";
	}
	cout << endl;
}
