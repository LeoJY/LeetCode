//210. Course Schedule II

//BFS
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
    	vector<unordered_set<int>> graph = makeGraph(numCourses, prerequisites);
        vector<int> degree = computeDegree(graph);
        vector<int> result;
        for (int i = 0; i < numCourses; i++){
            int j = 0;
            for(; j< numCourses; j++){
                if (degree[j] == 0) break;
            }
            if (j == numCourses) return {};
            degree[j] = -1;
            result.push_back(j);
            for (auto i : graph[j]) degree[i] --;
        }
        return result;
    }
private:
    vector<unordered_set<int>> makeGraph(int numCourses, vector<pair<int, int>>& prerequisites){
        vector<unordered_set<int>> result(numCourses);
        for (auto i : prerequisites) result[i.second].insert(i.first);
        return result;
    }
    vector<int> computeDegree(vector<unordered_set<int>>& graph){
        vector<int> result(graph.size(), 0);
        for (auto i : graph){
            for (auto j : i){
                result[j]++;
            }
        }
        return result;
	}
};


//DFS
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<unordered_set<int>> graph = makeGraph(numCourses, prerequisites);
    	vector<bool> visited(numCourses, false);
    	vector<bool> onPath(numCourses, false);
    	vector<int> result;
    	for (int i = 0; i < numCourses; i++){
    		if (dfsCycle(graph, i, visited, onPath, result)) return{};
    	}
    	reverse(result.begin(), result.end());
    	return result;
    }
private:
	vector<unordered_set<int>> makeGraph(int numCourses, vector<pair<int, int>>& prerequisites){
		vector<unordered_set<int>> result(numCourses);
		for (auto i : prerequisites) result[i.second].insert(i.first);
		return result;
	}
	bool dfsCycle(vector<unordered_set<int>>& graph, int node, vector<bool>& visited, vector<bool>& onPath, vector<int>& result){
		if (visited[node]) return false;
		visited[node] = true;
		onPath[node] = true;
		for (auto i : graph[node]){
			if (onPath[i] || dfsCycle(graph, i, visited, onPath, result)) return true;
		}
		onPath[node] = false;
		result.push_back(node);
		return false;
    }
};