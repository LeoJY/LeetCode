//261. Graph Valid Tree
//Given n nodes labeled from 0 to n - 1 and a list of undirected edges (each edge is a pair of nodes), write a function to check whether these edges make up a valid tree.
//Hint:
//Given n = 5 and edges = [[0, 1], [1, 2], [3, 4]], what should your return? Is this case a valid tree?
//According to the definition of tree on Wikipedia: “a tree is an undirected graph in which any two vertices are connected by exactly one path. In other words, any connected graph without simple cycles is a tree.”
//Note: you can assume that no duplicate edges will appear in edges. Since all edges are undirected, [0, 1] is the same as [1, 0] and thus will not appear together in edges.

class UF{
private:
	int count;
	int* parent;
	int* rank;
public:
	UF(int n){
		count = n;
		parent = new int[n];
		rank = new int[n];
		for (int i = 0; i < n; i++){
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
	int getCount(){return count;}
	bool connected(int x, int y){return find(x) == find(y);}
	void connect(int x, int y){
		int px = find(x);
		int py = find(y);
		if (px == py) return;
		if (rank[px] > rank[py]) parent[py] = px;
		else if (rank[py] > rank[px]) parent[px] = py;
		else {
			parent[px] = py;
			rank[py] ++;
		}
		count --;
	}
};

class Solution {
public:
    bool validTree(int n, vector<pair<int, int>>& edges) {
        UF *uf = new UF(n);
        for (auto i : edges){
        	int x = i.first, y = i.second;
        	if (uf -> connected(x, y)) return false;
        	uf -> connect(x, y);
        }
        return (uf -> getCount() == 1);
    }
};
