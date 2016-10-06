//73. Set Matrix Zeroes
//Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in place.

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
    	bool col0 = false;
    	int row = matrix.size();
    	int col = matrix[0].size();
    	for (int i = 0; i < row; ++i)
    	{
    		if (matrix[i][0] == 0) col0 = true;
    		for (int j = 1; j < col; ++j)
    		{
    			if (matrix[i][j] == 0)
    			{
    				matrix[i][0] = 0;
    				matrix[0][j] = 0;
    			}
    		}
    	}
    	for (int i = row - 1; i >= 0; --i)
    	{
    		for (int j = col - 1; j > 0; --j)
    		{
    			if (matrix[i][0] == 0 || matrix[0][j] == 0)
    			{
    				matrix[i][j] =0;
    			}
    		}
    		if (col0)
    		{
    			matrix[i][0] = 0;
    		}
    	}

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

	testcase.setZeroes(testmatrix);

	for (int i = 0; i < testrow; ++i)
	{
		for (int j = 0; j < testcol; ++j)
		{
			cout << testmatrix[i][j] << '\t';
		}
		cout << endl;
	}

	return 0;
}