#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    vector<int> searchRange(int A[], int n, int target){
		vector<int> result = {-1, -1};
		if(n == 0) return result;
		help(A, 0, n - 1, target, result);
		return result;
	}

	void help(int A[], int a, int b, int target, vector<int>& result){
		if(a > b) return;
		if(A[(a + b) / 2] > target){
			help(A, a, (a + b) / 2 - 1, target, result);
		}
		else if(A[(a + b) / 2] < target){
			help(A, (a + b) / 2 + 1, b, target, result);
		}
		else{
			if(result[0] == -1){
				result[0] = (a + b) / 2;
				result[1] = (a + b) / 2;
			}
			else{
				if((a + b) / 2 > result[1]){
					result[1] = (a + b) / 2;
				}
				if((a + b) / 2 < result[0]){
					result[0] = (a + b) / 2;
				}
			}
			help(A, a, (a + b) / 2 - 1, target, result);
			help(A, (a + b) / 2 + 1, b, target, result);
		}
    }
};

int main(){
	int A[] = {5, 7, 7, 8, 8, 10};
	int n = 6;
	int target = 10;
	Solution soln;
	vector<int> result = soln.searchRange(A, n, target);
	cout << "[" << result[0] << ", " << result[1] << "]" << endl;
}
