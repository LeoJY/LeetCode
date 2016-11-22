//130. Surrounded Regions
//Given a 2D board containing 'X' and 'O' (the letter O), capture all regions surrounded by 'X'.
//A region is captured by flipping all 'O's into 'X's in that surrounded region.
//DFS
class Solution {
public:
    void solve(vector<vector<char>>& board) {
    	if(board.empty()) return;
    	row = board.size();
    	col = board[0].size();
    	for (int i = 0; i < row; i++){
    		helper(board, i, 0);
    		if (col > 1) helper(board, i, col - 1);
    	}
    	for (int i = 1; i < col - 1; i++){
    		helper(board, 0, i);
    		if (row > 1) helper(board, row - 1, i);
    	}
    	for (int i = 0; i < row; i++){
    		for (int j = 0; j < col; j++){
    			if (board[i][j] == 'O') board[i][j] = 'X';
    			else if (board[i][j] == '1') board[i][j] = 'O';
    		}
    	}
    }
private:
	int row, col;
	void helper(vector<vector<char>>& board, int x, int y){
		if (board[x][y] == 'O'){
			board[x][y] = '1';
			if (x > 1) helper(board, x - 1, y);
			if (y > 1) helper(board, x, y - 1);
			if (x < row - 1) helper(board, x + 1, y);
			if (y < col - 1) helper(board, x, y + 1);
		}
	}
};

//union find

class UF{
public:
	UF(int n){
		count = n;
		parent = new int[n];
		rank = new int[n];
		for (int i = 0; i < n; i ++){
			parent[i] = i;
			rank[i] = 0;
		}
	}

	~UF(){
		delete parent;
		delete rank;
	}

	int find(int x){
		while(parent[x] != x){
			parent[x] = parent[parent[x]];
			x = parent[x];
		}
		return x;
	}

	int getCount() {return count;}

	bool connected(int x, int y){return find(x) == find(y);}

	void connect(int x, int y){
		int px = find(x);
		int py = find(y);
		if (px == py) return;
		if (rank[px] > rank[py]) parent[py] = px;
		else if (rank[px] < rank[py]) parent[px] = py;
		else{
			parent[py] = px;
			rank[px] ++;
		}
		count --;
	}

private:
	int* parent;
	int count;
	int* rank;
};

class Solution {
public:
    void solve(vector<vector<char>>& board) {
    	int n = board.size();
    	if (n == 0) return;
    	int m = board[0].size();
    	if (m == 0) return;
    	UF uf = UF(n * m + 1);
    	for (int i = 0; i < n; i ++){
    		for (int j = 0; j < m; j++){
    			if ((i == 0 || j == 0 || i == n - 1 || j == m - 1) && board[i][j] =='O') uf.connect(i * m + j, m * n);
    			else if (board[i][j] == 'O'){
    				if (board[i + 1][j] == 'O') uf.connect((i + 1) * m + j, i * m + j);
    				if (board[i - 1][j] == 'O') uf.connect((i - 1) * m + j, i * m + j);
    				if (board[i][j + 1] == 'O') uf.connect(i * m + j + 1, i * m + j);
    				if (board[i][j - 1] == 'O') uf.connect(i * m + j - 1, i * m + j);
    			}
    		}
    	}
    	for (int i = 0; i < n; i ++){
    		for (int j = 0; j < m; j++){
    			if (!uf.connected(i * m + j, m * n)) board[i][j] = 'X';
    		}
    	}
	}
};




