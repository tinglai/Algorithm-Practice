#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    bool exist(vector<vector<char> > &board, string word) {
		if(word.length() == 0) return true;
		int x = 0;
		int y = 0;
		int xLength = board[0].size();
		int yLength = board.size();

		vector<vector<bool>> ifChecked(board.size(), vector<bool>(board[0].size(), false));

		while(x < xLength && y < yLength){
			findStart(x, y, board, word[0]);
			if(x < xLength && y < yLength){
				ifChecked[y][x] = true;
			}
			if(search(x, y, board, ifChecked, word.substr(1))){
				return true;
			}
			if(x < xLength && y < yLength){
				ifChecked[y][x] = false;
			}
			if(x + 1 < xLength) x++;
			else{
				x = 0;
				y++;
			}
		}
		return false;
    }
	void findStart(int& x, int& y, vector<vector<char>>& board, char letter){
		//find where to start the search
		//if fail to find the start point, x and y will be e
		int xLength = board[0].size();
		int yLength = board.size();
		
		int xidx;

		for(xidx = x; xidx < xLength; xidx++){
			if(board[y][xidx] == letter){
				x = xidx;
				return;
			}
		}
		y = y + 1;
		for(; y < yLength; y++){
			for(x = 0; x < xLength; x++){
				if(board[y][x] == letter){
					return;
				}
			}
		}
	}
	bool search(int x, int y, vector<vector<char>>& board, vector<vector<bool>>& ifChecked, string word){
		int xLength = board[0].size();
		int yLength = board.size();

		if(x >= xLength) return false;
		if(y >= yLength) return false;
		if(word.length() == 0) return true;
		if(x + 1 < xLength){
			if(ifChecked[y][x + 1] == false && board[y][x + 1] == word[0]){
				if(word.length() == 1) return true;
				ifChecked[y][x + 1] = true;
				if(search(x + 1, y, board, ifChecked, word.substr(1)) == true){
					return true;
				}
				else{
					ifChecked[y][x + 1] = false;
				}
			}
		}
		if(x - 1 >= 0){
			if(ifChecked[y][x - 1] == false && board[y][x - 1] == word[0]){
				if(word.length() == 1) return true;
				ifChecked[y][x - 1] = true;
				if(search(x - 1, y, board, ifChecked, word.substr(1)) == true){
					return true;
				}
				else{
					ifChecked[y][x - 1] = false;
				}
			}
		}
		if(y + 1 < yLength){
			if(ifChecked[y + 1][x] == false && board[y + 1][x] == word[0]){
				if(word.length() == 1) return true;
				ifChecked[y + 1][x] = true;
				if(search(x, y + 1, board, ifChecked, word.substr(1)) == true){
					return true;
				}
				else{
					ifChecked[y + 1][x] = false;
				}
			}
		}
		if(y - 1 >= 0){
			if(ifChecked[y - 1][x] == false && board[y - 1][x] == word[0]){
				if(word.length() == 1) return true;
				ifChecked[y - 1][x] = true;
				if(search(x, y - 1, board, ifChecked, word.substr(1)) == true){
					return true;
				}
				else{
					ifChecked[y - 1][x] = false;
				}
			}
		}
		return false;
	}
};

int main(){
	string word;
	cout << "word = ";
	cin >> word;
	vector<vector<char>> board = {
{'a'}};
/*
		{'C', 'A', 'A'},
		{'A', 'A', 'A'},
		{'B', 'C', 'D'}
	};
  {'A', 'B', 'C', 'E'},
  {'S', 'F', 'C', 'S'},
  {'A', 'D', 'E', 'E'}};
*/
	Solution soln;
	if(soln.exist(board, word)){
		cout << word << " exits in the board" << endl;
	}
	else{
		cout << word << " doesn't exits in the board" << endl;
	}
}
