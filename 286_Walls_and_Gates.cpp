//286. Walls and Gates
//You are given a m x n 2D grid initialized with these three possible values.
//-1 - A wall or an obstacle.
//0 - A gate.
//INF - Infinity means an empty room. We use the value 231 - 1 = 2147483647 to represent INF as you may assume that the distance to a gate is less than 2147483647.
//Fill each empty room with the distance to its nearest gate. If it is impossible to reach a gate, it should be filled with INF.


class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        if (rooms.empty() || rooms[0].empty()) return;
        vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        int row = rooms.size(), col = rooms[0].size();
        queue<pair<x, y>> myQueue;
        for (int i = 0; i < row; i ++){
        	for (int j = 0; j < col; j++){
        		if (rooms[i][j] == 0) myQueue.push(make_pair(i, j));
        	}
        }
        while(myQueue.size()){
        	auto temp = myQueue.front();
        	myQueue.pop();
        	for (auto dir : directions){
        		int x = temp.first + dir.first;
        		int y = temp.second + dir.second;
        		if (x < 0 || x >= row || y < 0 || y >= col || rooms[x][y] <= rooms[temp.first][temp.second] + 1) continue;
        		rooms[x][y] = rooms[temp.first][temp.second] + 1;
        		myQueue.push(make_pair(x, y));
        	}
        }
    }
};