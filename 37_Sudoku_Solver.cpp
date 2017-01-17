//37. Sudoku Solver
//Write a program to solve a Sudoku puzzle by filling the empty cells.
//Empty cells are indicated by the character '.'.
//You may assume that there will be only one unique solution.


class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        if (board.empty() || board[0].empty()) return;
        helper(board);
    }
private:
	bool helper(vector<vector<char>>& board){
		for (int i = 0; i < board.size(); i ++){
			for (int j = 0; j < board[0].size(); j ++){
				if (board[i][j] != '.') continur;
				for (k = '1'; k <= '9'; k ++){
					if (isValid(board, i, j, k)){
						board[i][j] = k;
						if (helper(board)) return true;
						board[i][j] = '.';
					}
				}
				return false;
			}
		}
		return true;
	}
	bool isValid(vector<vector<char>>& board, int i, int j, char k){
		for (int x = 0; x < 9; x++){
			if (board[i][x]!= '.' && board[i][x] == k) return false;
			if (board[x][y]!= '.' && board[x][y] == k) return false;
			if (board[(i / 3) * 3 + x / 3][(j / 3) * 3 + x % 3] != '.' && board[(i / 3) * 3 + x / 3][(j / 3) * 3 + x % 3] == k) return false;
		}
		return true;
	}
};
