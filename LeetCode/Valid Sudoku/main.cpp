#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    bool isValidSudoku(vector<vector<char>> &board){
		vector<vector<bool>> row(9, vector<bool>(9, false));
		vector<vector<bool>> column(9, vector<bool>(9, false));
		vector<vector<bool>> cube(9, vector<bool>(9, false));

		for(int i = 0; i < 9; i++){
			for(int j = 0; j < 9; j++){
				char cur = board[i][j];
				if(cur == '.') continue;
				else{
					int readin = (int)cur - (int)'1';//note here the substracted number should be 1
													 //instead of 0 as normal
													 //otherwise in later's index, need readin - 1 if
													 //we use 0
					if(row[i][readin] == true) return false;
					else row[i][readin] = true;
					if(column[j][readin] == true) return false;
					else column[j][readin] = true;
					int a = i / 3;
					int b = j / 3;
					int cubeIdx = a * 3 + b;
					if(cube[cubeIdx][readin] == true) return false;
					else cube[cubeIdx][readin] = true;
				}
			}
		}
		return true;
    }
};

int main(){
/*
	vector<vector<char>> board = {
									{'5', '3', '.', '.', '7', '.', '.', '.', '.'},
									{'6', '.', '.', '1', '9', '5', '.', '.', '.'},
									{'.', '9', '8', '.', '.', '.', '.', '6', '.'},
									{'8', '.', '.', '.', '6', '.', '.', '.', '3'},
									{'4', '.', '.', '8', '.', '3', '.', '.', '1'},
									{'7', '.', '.', '.', '2', '.', '.', '.', '6'},
									{'.', '6', '.', '.', '.', '.', '2', '8', '.'},
									{'.', '.', '.', '4', '1', '9', '.', '.', '5'},
									{'.', '.', '.', '.', '8', '.', '.', '7', '9'},
								 };
*/

	vector<string> board = {"..5.....6","....14...",".........",".....92..","5....2...",".......3.","...54....","3.....42.","...27.6.."};
	Solution soln;
	bool result = soln.isValidSudoku(board);
	if(result) cout << "valid" << endl;
	else cout << "not valid" << endl;
}
