//310. Minimum Height Trees
//For a undirected graph with tree characteristics, we can choose any node as the root. The result graph is then a rooted tree. Among all possible rooted trees, those with minimum height are called minimum height trees (MHTs). Given such a graph, write a function to find all the MHTs and return a list of their root labels.
//Format
//The graph contains n nodes which are labeled from 0 to n - 1. You will be given the number n and a list of undirected edges (each edge is a pair of labels).
//You can assume that no duplicate edges will appear in edges. Since all edges are undirected, [0, 1] is the same as [1, 0] and thus will not appear together in edges.
//Hint:
//How many MHTs can a graph have at most?
//Note:
//(1) According to the definition of tree on Wikipedia: “a tree is an undirected graph in which any two vertices are connected by exactly one path. In other words, any connected graph without simple cycles is a tree.”
//(2) The height of a rooted tree is the number of edges on the longest downward path between the root and a leaf.

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
        vector<vector<int>> path(n);
        vector<int> count (n, 0);
        vector<int> result;
        for(auto i : edges){
        	count[i.first] ++;
        	count[i.second] ++;
        	path[i.first].push_back(i.second);
        	path[i.second].push_back(i.first);
        }
        queue<int>leaves;
        for (int i = 0; i < n; i ++){
        	if (count[i] <= 1) leaves.push(i);
        }
        while(n > 2){
        	int num = leaves.size();
        	n -= num;
        	for (int i = 0; i < num; i++){
        		auto temp = leaves.front();
        		leaves.pop();
        		for (auto j : path[temp]){
        			if (-- count[j] == 1) leaves.push(j);
        		}
        	}
        }
        while(leaves.size()){
        	result.push_back(leaves.front());
        	leaves.pop();
        }
        return result;
    }
};






