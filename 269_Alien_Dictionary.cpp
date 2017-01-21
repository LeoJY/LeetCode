//269. Alien Dictionary
//There is a new alien language which uses the latin alphabet. However, the order among letters are unknown to you. You receive a list of words from the dictionary, where words are sorted lexicographically by the rules of this new language. Derive the order of letters in this language.
//Note:
//You may assume all letters are in lowercase.
//If the order is invalid, return an empty string.
//There may be multiple valid order of letters, return any one of them is fine.

class Solution {
public:
    string alienOrder(vector<string>& words) {
    	string result = "";
    	for (int i = 0; i < words.size() - 1; i++){
    		if (words[i].size() > words[i + 1].size() && words[i].substr(0, words[i + 1].size()) == words[i + 1]) return "";
    	}    
    	unordered_set<char> charCount;
    	for (auto i : words) charCount.insert(i.begin(), i.end());
    	unordered_map<char, unordered_set<char>> graph = makeGraph(words);
    	unordered_map<char, int> degree = countDegree(charCount, graph);
    	for (int i = 0; i < charCount.size(); i++){
    		auto j = degree.begin();
    		for (; j != degree.end(); j++){
    			if (j -> second == 1) break;
    		}
    		if (j == degree.end()) return "";
    		j -> second = -1;
    		result += j -> first;
    		for (auto k : graph[j -> first]) degree[k]--;
    	}
    	return result;
    }
private:
	unordered_map<char, unordered_set<char>> makeGraph(vector<string>& words){
		int maxSize = 0;
		unordered_map<char, unordered_set<char>> result;
		for (auto i : words) maxSize = max(maxSize, (int)i.size());
		for (int i = 0; i < maxSize; i++){
			for (int j = 0; j < words.size() - 1; j ++){
				if (words[j].size() <= i) continue;
				for (int k = j + 1; k < words.size(); k ++){
					if (words[k].size() <= i || words[j].substr(0, i) != words[k].substr(0, i)) break;
					if (words[j][i] != words[k][i]) result[words[j][i]].insert(words[k][i]);
				}
			}
		}
		return result;
	}
	unordered_map<char, int> countDegree(unordered_set<char>& charCount, unordered_map<char, unordered_set<char>>& graph){
		unordered_map<char, int> result;
		for (auto i : charCount) result[i] = 1;
		for (auto i : graph){
			for (auto j : i.second){
				result[j] ++;
			}
		}
		return result;
	}
};