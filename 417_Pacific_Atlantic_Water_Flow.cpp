//417. Pacific Atlantic Water Flow
//Given an m x n matrix of non-negative integers representing the height of each unit cell in a continent, the "Pacific ocean" touches the left and top edges of the matrix and the "Atlantic ocean" touches the right and bottom edges.
//Water can only flow in four directions (up, down, left, or right) from a cell to another one with height equal or lower.
//Find the list of grid coordinates where water can flow to both the Pacific and Atlantic ocean.
//Note:
//The order of returned grid coordinates does not matter.
//Both m and n are less than 150.


class Solution {
public:
    vector<pair<int, int>> pacificAtlantic(vector<vector<int>>& matrix) {
        if(matrix.empty()) return result;
        row = matrix.size();
        col = matrix[0].size();
        visited.resize(row, vector<int>(col, 0));
        for (int i = 0; i < row; i++){
        	helper(matrix, i, 0, INT_MIN, 1);
        	helper(matrix, i, col - 1, INT_MIN, 2);
        }
        for (int i = 0; i < col; i++){
        	helper(matrix, 0, i, INT_MIN, 1);
        	helper(matrix, row - 1, i, INT_MIN, 2);
        }
        return result;
    }
private:
	int row;
	int col;
	vector<vector<int>> visited;
	vector<pair<int, int>> result;
	void helper(vector<vector<int>>& matrix, int x, int y, int pre, int ocean){
		if (x < 0 || y < 0 || x >= row || y >= col || pre > matrix[x][y] || (visited[x][y] & ocean) == ocean) return;
		visited[x][y] |= ocean;
		if (visited[x][y] == 3) result.push_back(make_pair(x, y));
		helper(matrix, x + 1, y, matrix[x][y], ocean);
		helper(matrix, x - 1, y, matrix[x][y], ocean);
		helper(matrix, x, y + 1, matrix[x][y], ocean);
		helper(matrix, x, y - 1, matrix[x][y], ocean);
	}
};

