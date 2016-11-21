//133. Clone Graph
//Clone an undirected graph. Each node in the graph contains a label and a list of its neighbors.

/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
//BFS

class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
    	if (node == NULL) return node;
    	UndirectedGraphNode* copy = new UndirectedGraphNode(node -> label);
    	myMap[node] = copy;
    	queue<UndirectedGraphNode*> myQueue;
    	myQueue.push(node);
    	while(!myQueue.empty()){
    		UndirectedGraphNode* temp = myQueue.front();
    		myQueue.pop();
    		for(auto i : temp -> neighbors){
    			if (myMap.find(i) == myMap.end()){
    				UndirectedGraphNode* newCopy = new UndirectedGraphNode(i -> label);
    				myQueue.push(i);
    				myMap[i] = newCopy;
    			}
    			myMap[temp] -> neighbors.push_back(myMap[i]);
    		}
    	}
    	return myMap[node];
    }
private:
	unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> myMap;
};


//DFS

class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
    	if (node == NULL) return node;
    	if (myMap.find(node) == myMap.end()){
    		myMap[node] = new UndirectedGraphNode(node -> label);
    		for (auto i : node -> neighbors){
    			myMap[node] -> neighbors.push_back(cloneGraph(i));
    		}
    	}
    	return myMap[node];
    }
private:
	unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> myMap;
};
