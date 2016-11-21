//200. Number of Islands
//Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.


//DFS
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
    	int count = 0;
    	row = grid.size();
    	if (row == 0) return 0;
    	col = grid[0].size();
    	for (int i = 0; i < row; i++){
    		for (int j = 0; j < col; j ++){
    			if (grid[i][j] == '1'){
    				count ++;
    				helper(grid, i, j);
    			}
    		}
    	}
    	return count;
    }
private:
	int row;
	int col;
	void helper(vector<vector<char>>& grid, int i, int j){
		if (i < 0 || j < 0 || i >= row || j >= col || grid[i][j] != '1') return;
		grid[i][j] = '0';
        helper(grid, i - 1, j);
        helper(grid, i + 1, j);
        helper(grid, i, j - 1);
        helper(grid, i, j + 1);
	}
};


//BFS
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
    	int count = 0;
    	row = grid.size();
    	if (row == 0) return 0;
    	col = grid[0].size();
    	for (int i = 0; i < row; i++){
    		for (int j = 0; j < col; j ++){
    			if (grid[i][j] == '1'){
    				count ++;
    				helper(grid, i, j);
    			}
    		}
    	}
    	return count;
    }
private:
	int row;
	int col;
	void helper(vector<vector<char>>& grid, int i, int j){
		queue<pair<int, int>> myQueue;
		myQueue.push(make_pair(i, j));
		while(!myQueue.empty()){
			auto temp = myQueue.front();
			myQueue.pop();
			int x = temp.first;
			int y = temp.second;
			grid[x][y] = '0';
			if (x > 0 && grid[x - 1][y] == '1'){
				myQueue.push(make_pair(x - 1, y));
				grid[x - 1][y] = '0';
			}
			if (y > 0 && grid[x][y - 1] == '1'){
				myQueue.push(make_pair(x, y - 1));
				grid[x][y - 1] = '0';
			}
			if (x < row - 1 && grid[x + 1][y] == '1'){
				myQueue.push(make_pair(x + 1, y));
				grid[x + 1][y] = '0';
			}
			if (y < col - 1 && grid[x][y + 1] == '1'){
				myQueue.push(make_pair(x, y + 1));
				grid[x][y + 1] = '0';
			}
		}
	}
};




