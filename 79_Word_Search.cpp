//79. Word Search
//Given a 2D board and a word, find if the word exists in the grid.
//The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
    	row = board.size();
    	col = board[0].size();
    	for (int i = 0; i < row; ++i)
    	{
    		for (int j = 0; j < col; ++j)
    		{
    			if (helper(board, word, i, j, 0)) return true;
    		}
    	}
    	return false;
    }

private:
	int row;
	int col;
	bool helper(vector<vector<char>>& board, const string word, int x, int y, int index){
		if (x < 0 || y < 0 || x >= row || y >= col || word[index] != board[x][y] || board[x][y] == '\0') return false;
		if (word[index + 1] == '\0') return true;
		char temp = board[x][y];
		board[x][y] = '\0';
		if (helper(board, word, x + 1, y, index + 1) || helper(board, word, x - 1, y, index + 1) || helper(board, word, x, y + 1, index + 1) || helper(board, word, x, y - 1, index + 1)) return true;
		board[x][y] = temp; 
		return false;
	}
};

int main()
{
	Solution testcase;
	int testrow, testcol;
	string teststring;
	cout << "please input the target string: " << endl;
	getline(cin, teststring);
	cout << "please input the matrix row and col:" << endl;
	cin >> testrow >> testcol;
	vector<vector<char>> testmatrix(testrow, vector<char>());
	cout << "please input the matrix:" <<endl;
	for (int i = 0; i < testrow; ++i)
	{
		for (int j = 0; j < testcol; ++j)
		{
			char temp;
			cout << "please input the matrix [" << i << "][" << j << "]: " << endl;
			cin >> temp;
			testmatrix[i].push_back(temp);
		}
	}

	bool result;
	result = testcase.exist(testmatrix, teststring);

	if (result) cout << "target found" << endl;
	else cout << "target not found" << endl;

	return 0;
}