//64. Minimum Path Sum
//Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.
//Note: You can only move either down or right at any point in time.

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
    	int row = grid.size();
    	int col = grid[0].size();
    	vector<int> dp (col, 0);
    	dp[0] = grid[0][0];
    	for (int i = 1; i < col; ++i)
    	{
    		dp[i] = grid[0][i] + dp[i - 1];
    	}
    	for (int i = 0; i < row; ++i)
    	{
    		dp[0] += grid[i][0];
    		for (int j = 1; j < col; ++j)
    		{
    			dp[j] = min( dp[j-1], dp[j]) + grid[i][j];
    		}
    	}
    	return dp[col - 1];
    }
};

int main()
{
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

	int result;
	result = testcase.minPathSum(testmatrix);

	cout << "the result is:" << result << endl;

	return 0;
}