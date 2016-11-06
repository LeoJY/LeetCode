//304. Range Sum Query 2D - Immutable
//Given a 2D matrix matrix, find the sum of the elements inside the rectangle defined by its upper left corner (row1, col1) and lower right corner (row2, col2).
//Note:
//You may assume that the matrix does not change.
//There are many calls to sumRegion function.
//You may assume that row1 ≤ row2 and col1 ≤ col2.

class NumMatrix {
public:
    NumMatrix(vector<vector<int>> &matrix) {
    	int n = matrix.size();
    	int m = n ? matrix[0].size() : 0;
    	vector<int> temp(m + 1, 0);
    	accumulator.push_back(temp);
    	for (int i = 0; i < n; i++){
    		int summation = 0;
    		for (int j = 0; j < m; j++){
    			summation += matrix[i][j];
    			temp[j + 1] += summation;
    		}
    		accumulator.push_back(temp);
    	}

    }

    int sumRegion(int row1, int col1, int row2, int col2) {
    	return accumulator[row2 + 1][col2 + 1] - accumulator[row1][col2 + 1] - accumulator[row2 + 1][col1] + accumulator[row1][col1];
    }
private:
	vector<vector<int>> accumulator;
};


// Your NumMatrix object will be instantiated and called as such:
// NumMatrix numMatrix(matrix);
// numMatrix.sumRegion(0, 1, 2, 3);
// numMatrix.sumRegion(1, 2, 3, 4);

