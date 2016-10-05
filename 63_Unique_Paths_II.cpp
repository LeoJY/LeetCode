//63. Unique Paths II
//Now consider if some obstacles are added to the grids. How many unique paths would there be?
//An obstacle and empty space is marked as 1 and 0 respectively in the grid.

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    	int m = obstacleGrid.size();
    	int n = obstacleGrid[0].size();
    	vector<int> result(n, 0);
    	result[0] = 1;
    	for (int i = 0; i < m; ++i)
    	{
    		for (int j = 0; j < n; ++j)
    		{
    			if (obstacleGrid[i][j])
    			{
    				result[j] = 0;
    			}
    			else if (j > 0){
    				result[j] += result[j - 1];
    			}
    		}
    	}
    	return result[n - 1];
    }
};

int main()
{
	Solution testcase;
	//input the target value and array
	cout << "input the matrix row number m:" << endl;
	int testsizem;
	cin >> testsizem;

	cout << "input the matrix col number n:" << endl;
	int testsizen;
	cin >> testsizen;
	
	vector<vector<int>> matrix(testsizem, vector<int>(testsizen));

	cout << "please input the matrix:" <<endl;
	for (int i = 0; i < testsizem; ++i)
	{
		for (int j = 0; j < testsizen; ++j)
		{
			cout << "please input the matrix [" << i << "][" << j << "]: " << endl;
			cin >> matrix[i][j];
		}
	}


	int result = testcase.uniquePathsWithObstacles(matrix);

	cout << "the result is: " << result << endl;
	return 0;
}