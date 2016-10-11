//289. Game of Life
//According to the Wikipedia's article: "The Game of Life, also known simply as Life, is a cellular automaton devised by the British mathematician John Horton Conway in 1970."
//Given a board with m by n cells, each cell has an initial state live (1) or dead (0). Each cell interacts with its eight neighbors (horizontal, vertical, diagonal) using the following four rules (taken from the above Wikipedia article):
//1.Any live cell with fewer than two live neighbors dies, as if caused by under-population.
//2.Any live cell with two or three live neighbors lives on to the next generation.
//3.Any live cell with more than three live neighbors dies, as if by over-population..
//4.Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.
//Write a function to compute the next state (after one update) of the board given its current state.
//Follow up: 
//Could you solve it in-place? Remember that the board needs to be updated at the same time: You cannot update some cells first and then use their updated values to update other cells.
//In this question, we represent the board using a 2D array. In principle, the board is infinite, which would cause problems when the active area encroaches the border of the array. How would you address these problems?

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	void gameOfLife(vector<vector<int>>& board) {
		int x = board.size();
		int y = board[0].size();
		for (int i = 0; i < x; ++i)
		{
			for (int j = 0; j < y; ++j)
			{
				int count = - board[i][j];
				for (int m = max(0, i - 1); m < min(x, i + 2); ++m)
				{
					for (int n = max(0, j - 1); n < min(y, j + 2); ++n)
					{
						count += board[m][n] & 1;
					}
				}
				if ((count | board[i][j]) == 3) board[i][j] |= 2;
			}
		}
		for (int i = 0; i < x; ++i)
		{
			for (int j = 0; j < y; ++j)
			{
				board[i][j] >>= 1;
			}
		}

	}
};

int main(){
	Solution testcase;
	int testrow, testcol;
	cout << "please input the matrix row and col:" << endl;
	cin >> testrow >> testcol;
	vector<vector<int>> testmatrix(testrow, vector<int>());
	cout << "please input the matrix:" <<endl;
	for (int i = 0; i < testrow; ++i)
	{
		for (int j = 0; j < testcol; ++j)
		{
			int temp;
			cout << "please input the matrix [" << i << "][" << j << "]: " << endl;
			cin >> temp;
			testmatrix[i].push_back(temp);
		}
	}

	testcase.gameOfLife(testmatrix);

	for (int i = 0; i < testrow; ++i)
	{
		for (int j = 0; j < testcol; ++j)
		{
			int temp;
			cout << testmatrix[i][j] << " ";
		}
		cout << endl;
	}
	return 0;

}