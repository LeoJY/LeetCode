//399. Evaluate Division
//Equations are given in the format A / B = k, where A and B are variables represented as strings, and k is a real number (floating point number). Given some queries, return the answers. If the answer does not exist, return -1.0.
//The input is: vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries , where equations.size() == values.size(), and the values are positive. This represents the equations. Return vector<double>.

class Solution {
public:
    vector<double> calcEquation(vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries) {
    	unordered_map<string, Node*> myMap;
    	vector<double> result;
    	for (int i = 0; i < equations.size(); i++){
    		string s1 = equations[i].first; 
    		string s2 = equations[i].second;
    		if (myMap.find(s1) == myMap.end() && myMap.find(s2) == myMap.end()){
    			myMap[s1] = new Node(values[i]);
    			myMap[s2] = new Node(1.0);
    			myMap[s2] -> parent = myMap[s1];
    		}
    		else if (myMap.find(s1) == myMap.end()){
    			myMap[s1] = new Node(myMap[s2] -> value * values[i]);
    			myMap[s1] -> parent = myMap[s2];
    		}
    		else if (myMap.find(s2) == myMap.end()){
    			myMap[s2] = new Node(myMap[s1] -> value / values[i]);
    			myMap[s2] -> parent = myMap[s1];
    		}
    		else {
    			unionNode(myMap[s1], myMap[s2], values[i], myMap);
    		}
    	}
    	for (auto i : queries){
    		if (myMap.count(i.first) == 0 || myMap.count(i.second) == 0 || findParent(myMap[i.first]) != findParent(myMap[i.second])) result.push_back(-1);
    		else result.push_back(myMap[i.first] -> value / myMap[i.second] -> value);
    	}
    	return result;
    }
private:
	struct Node{
		double value;
		Node* parent;
		Node(double x){
			value = x;
			parent = this;
		}
	};

	Node* findParent(Node* temp){
		while(temp -> parent != temp){
			temp -> parent = temp -> parent -> parent;
			temp = temp -> parent;
		}
		return temp;
	}

	void unionNode(Node* node1, Node* node2, double num, unordered_map<string, Node*>& map){
		Node* pNode1 = findParent(node1);
		Node* pNode2 = findParent(node2);
		double ratio = node2 -> value * num / node1 -> value;
		for(auto i : map){
			if (findParent(i.second) == pNode1) i.second -> value *= ratio;
		}
		pNode1 -> parent = pNode2;
	}
};


