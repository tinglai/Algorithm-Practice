#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution{
public:
    void solveSudoku(vector<vector<char> > &board){
		unordered_set<char> temp;
		for(int i = 0; i < 9; i++){
			temp.insert('1' + i);
		}
		vector<unordered_set<char>> row(9, unordered_set<char>(temp));
		vector<unordered_set<char>> column(9, unordered_set<char>(temp));
		vector<unordered_set<char>> matrix(9, unordered_set<char>(temp));
		vector<char> blankEntries;
		vector<vector<char>> tempBoard = board;
		for(unsigned int i = 0; i < 9; i++){
			for(unsigned int j = 0; j < 9; j++){
				if(board[i][j] != '.'){
					row[i].erase(board[i][j]);
					column[j].erase(board[i][j]);
					matrix[(i / 3) * 3 + j / 3].erase(board[i][j]);
				}
				else{
					blankEntries.push_back(i);
					blankEntries.push_back(j);
				}
			}
		}
		help(tempBoard, row, column, matrix, blankEntries, 0, board);
    }
	void help(vector<vector<char>>& tempBoard, vector<unordered_set<char>>& row, vector<unordered_set<char>>& column,
			  vector<unordered_set<char>>& matrix, vector<char>& blankEntries, int itr, vector<vector<char>>& board){
		if(itr == (int)blankEntries.size()){
			board = tempBoard;
			return;
		}
		int i = blankEntries[itr];
		int j = blankEntries[itr + 1];
		if(row[i].empty()
		  && column[j].empty()
		  && matrix[(i / 3) * 3 + j / 3].empty()){
			return;
		}
		for(int t = 0; t < 9; t++){
			char tChar = '1' + t;
			if(row[i].count(tChar) > 0
				  && column[j].count(tChar) > 0
				  && matrix[(i / 3) * 3 + j / 3].count(tChar) > 0){
				tempBoard[i][j] = tChar;
				row[i].erase(tChar);
				column[j].erase(tChar);
				matrix[(i / 3) * 3 + j / 3].erase(tChar);
				help(tempBoard, row, column, matrix, blankEntries, itr + 2, board);
				tempBoard[i][j] = '.';
				row[i].insert(tChar);
				column[j].insert(tChar);
				matrix[(i / 3) * 3 + j / 3].insert(tChar);
			}
		}
	}
};

int main(){
	vector<vector<char>> board = {
								{'5','3','.','.','7','.','.','.','.'},
								{'6','.','.','1','9','5','.','.','.'},
								{'.','9','8','.','.','.','.','6','.'},
								{'8','.','.','.','6','.','.','.','3'},
								{'4','.','.','8','.','3','.','.','1'},
								{'7','.','.','.','2','.','.','.','6'},
								{'.','6','.','.','.','.','2','8','.'},
								{'.','.','.','4','1','9','.','.','5'},
								{'.','.','.','.','8','.','.','7','9'},
							};
	Solution soln;
	soln.solveSudoku(board);
	for(int i = 0; i < 9; i++){
		for(int j = 0; j < 9; j++){
			cout << board[i][j] << " ";
		}
		cout << endl;
	}
}
