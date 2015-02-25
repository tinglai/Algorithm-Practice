#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    int totalNQueens(int n){
		vector<bool> column(n, false); // false means no queen on column[i]
		vector<bool> diag1(2 * n - 1, false);
		vector<bool> diag2(2 * n - 1, false);
		int result = 0;
		help(n, 0, column, diag1, diag2, result);
		return result;
    }
	void help(int n, int rowIdx, vector<bool>& column, vector<bool>& diag1,
			 vector<bool>& diag2, int& count){
		if(rowIdx == n){
			count++;
			return;
		}

		for(int i = 0; i < n; i++){
			if(column[i] || diag1[rowIdx - i + 2 * n - 1]
			   || diag2[rowIdx + i]) continue;
			column[i] = true;
			diag1[rowIdx - i + 2 * n - 1] = true;
			diag2[rowIdx + i] = true;
			help(n, rowIdx + 1, column, diag1, diag2, count);
			column[i] = false;
			diag1[rowIdx - i + 2 * n - 1] = false;
			diag2[rowIdx + i] = false;
		}
	}
};

int main(){
	int n;
	cout << "n = "; cin >> n;
	Solution soln;
	int result = soln.totalNQueens(n);
	cout << "result = " << result << endl;
}
