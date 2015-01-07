#include <iostream>
#include <unordered_set>
#include <cmath>

using namespace std;

class Solution1{
//this is not really using a constant space
public:
    int firstMissingPositive(int A[], int n){
		unordered_set<int> store;
		for(int i = 0; i < n; i++){
			if(A[i] > 0){
				store.insert(A[i]);
			}
		}
		int i = 1;
		while(true){
			if(store.count(i) == 0){
				return i;
			}
			i++;
		}
    }
};

class Solution {
//now let's try to do the job using constant space
public:
    int firstMissingPositive(int A[], int n){
		if(n <= 0) return 1;
		int i = 0;
		int j = n - 1;
		int num = 0;
		//put all the positive numbers in front of the array
		//meanwhile keep record of the number of the positive numbers
		while(i <= j){
			while(A[i] > 0){
				i++;
				num++;
				if(i == n) break;
			}
			while(A[j] <= 0){
				j--;
				if(j < 0) break;
			}
			if(i < j){
				int temp = A[i];
				A[i] = A[j];
				A[j] = temp;
				num++;
				i++;
				j--;
			}
		}
		for(i = 0; i < num; i++){
		//the first missing positive number will only occur in [1, num + 1]
		//and we know that the first num numbers in A are positive	
			int temp = abs(A[i]);
			if(temp - 1 < num){
				if(A[temp - 1] > 0){
					A[temp - 1] = -A[temp - 1];
				}
			}
		//we set all of those A[i] negative, if i is among A[0] and A[num - 1]
		}
		for(i = 0; i < num; i++){
			if(A[i] > 0) return i + 1;
		}
		return num + 1;
    }
};

int main(){
	int A[] = {1, 1};
	int n = 2;
	Solution soln;
	int result = soln.firstMissingPositive(A, n);
	cout << "result = " << result << endl;
}
