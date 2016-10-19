//36. Valid Sudoku
//Determine if a Sudoku is valid, according to: Sudoku Puzzles - The Rules.
//The Sudoku board could be partially filled, where empty cells are filled with the character '.'.

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    bool isValidSudoku(vector<vector<char> > &board){
    	bool used1[9][9] = {false}, used2[9][9] = {false}, used3[9][9] = {false};
    	for (int i = 0; i < board.size(); ++i)
    	{
    		for (int j = 0; j < board[i].size(); ++j)
    		{
    			if (board[i][j] != '.'){
    				int temp = board[i][j] - '0' - 1;
    				int k = i / 3 * 3 + j / 3;
    				if (used1[i][temp] || used2[j][temp] || used3[k][temp]) return false;
    				else used1[i][temp] = used2[j][temp] = used3[k][temp] = true;
    			}
    		}
    	}
    	return true;
    }
};

int main(){
	Solution testCase;
	vector<vector<char>> testBoard (9, vector<char>(9, '.'));
	cout << "please input the sudoku board, empty slot should be '.' " << endl;
	for (int i = 0; i < 9; ++i)
	{
		for (int j = 0; j < 9; ++j)
		{
			cout << "please input the board[" << i << "][" << j << "]" << endl;
			cin >> testBoard[i][j];
		}
	}
	bool testResult = testCase.isValidSudoku(testBoard);
	if (testResult) cout << "input board valid" << endl;
	else cout << "input board invalid" << endl;
	return 0;
}