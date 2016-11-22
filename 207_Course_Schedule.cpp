//207. Course Schedule
//There are a total of n courses you have to take, labeled from 0 to n - 1.
//Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]
//Given the total number of courses and a list of prerequisite pairs, is it possible for you to finish all courses?

//BFS
class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<unordered_set<int>> graph = makeGraph(numCourses, prerequisites);
        vector<int> degree = computeDegree(graph);
        for (int i = 0; i < numCourses; i++){
            int j = 0;
            for(; j< numCourses; j++){
                if (degree[j] == 0) break;
            }
            if (j == numCourses) return false;
            degree[j] = -1;
            for (auto i : graph[j]) degree[i] --;
        }
        return true;
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
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
    	vector<unordered_set<int>> graph = makeGraph(numCourses, prerequisites);
    	vector<bool> visited(numCourses, false);
    	vector<bool> onPath(numCourses, false);
    	for (int i = 0; i < numCourses; i++){
    		if (dfsCycle(graph, i, visited, onPath)) return false;
    	}
    	return true;
    }
private:
	vector<unordered_set<int>> makeGraph(int numCourses, vector<pair<int, int>>& prerequisites){
		vector<unordered_set<int>> result(numCourses);
		for (auto i : prerequisites) result[i.second].insert(i.first);
		return result;
	}
	bool dfsCycle(vector<unordered_set<int>>& graph, int node, vector<bool>& visited, vector<bool>& onPath){
		if (visited[node]) return false;
		visited[node] = true;
		onPath[node] = true;
		for (auto i : graph[node]){
			if (onPath[i] || dfsCycle(graph, i, visited, onPath)) return true;
		}
		onPath[node] = false;
		return false;
	}
};