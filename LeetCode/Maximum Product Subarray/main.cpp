#include <iostream>
#include <climits>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

/*
class Solution{
//this method can also be used in the case of double array
//and the time complexity is O(n^2) and space complexity is O(n)
public:
    int maxProduct(int A[], int n){
		if(n == 1) return A[0];
		vector<int> memo;
		//memo[i] = product of numbers from A[n - i] to A[n - (memo.size() - 1)]
		
		int result = A[n - 1];
		for(int i = n - 1; i >= 0; i--){
			if(A[i] > result) result = A[i];
			if(A[i] == 1) continue;
			for(unsigned int j = 0; j < memo.size(); j++){
				memo[j] = memo[j] * A[i];
				if(memo[j] > result) result = memo[j];
			}
			memo.push_back(A[i]);
		}

		return result;
    }
};
*/

class Solution{
//we can also solve this problem using the fact that the abs value of the  
//product of integer is non-decreasing. Then we can find that actuall the possible
//result will either contain the first number of the last number of the array
//regardless the case that some number will be 0
public:
    int maxProduct(int A[], int n){
		if(n == 1) return A[0];

		int result = A[0];

		int b = 1;
		int e = 1;
		for(int i = 0; i < n; i++){
			result = max(result, max(b *= A[i], e *= A[n - 1 - i]));
			if(b == 0) b = 1;
			if(e == 0) e = 1;
		}

		return result;
    }
};


int main(){
	//int A[] = {-3, 0, 1, -2};
	int A[] = {-2, 0, -4};
	int n = 3;
	Solution soln;
	int result = soln.maxProduct(A, n);
	cout << "result = " << result << endl;
}
