#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// another method which is in-place
// that is, to firstly reverse the whole array
// then reverse the two subarray separately again
class Solution{
public:
    void rotate(int nums[], int n, int k){
		if(n == 0) return;
		int m = k % n;
		if(m == 0) return;
		for(int i = 0; i < n / 2; i++){
			swap(nums[i], nums[n - 1 - i]);
		}
		for(int i = 0; i < m / 2; i++){
			swap(nums[i], nums[m - 1 - i]);
		}
		for(int i = 0; i < (n - m) / 2; i++){
			swap(nums[m + i], nums[n - 1 - i]);
		}
    }
};


/*
class Solution{
public:
    void rotate(int nums[], int n, int k){
		if(n == 0) return;
		int m = k % n;
		if(m == 0) return;
		vector<int> memo(m);
		for(int i = 0; i < m; i++){
			memo[i] = nums[n - m + i];
		}
		for(int i = 0; i < n - m; i++){
			nums[n - 1 - i] = nums[n - 1 - i - m];
		}
		for(int i = 0; i < m; i++){
			nums[i] = memo[i];
		}
    }
};
*/

int main(){
	int nums[] = {1,2,3,4,5,6,7};
	int n = 7, k = 3;
	Solution soln;
	soln.rotate(nums, n, k);
	for(int i = 0; i < n; i++){
		cout << nums[i] << ' ';
	}
	cout << endl;
}
