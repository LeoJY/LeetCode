//126. Word Ladder II
//Given two words (beginWord and endWord), and a dictionary's word list, find all shortest transformation sequence(s) from beginWord to endWord, such that:
//Only one letter can be changed at a time
//Each intermediate word must exist in the word list
//Note:
//All words have the same length.
//All words contain only lowercase alphabetic characters.

class Solution {
public:
    vector<vector<string>> findLadders(string start, string end, unordered_set<string> &wordList) {
        unordered_set<string> startWord, endWord;
        vector<string>ladder;
        vector<vector<string>> ladders;
        startWord.insert(start);
        endWord.insert(end);
        ladder.push_back(start);
        bool flip = true;
        unordered_map<string, vector<string>> children;
        if (searchLadder(startWord, endWord, children, wordList, flip)){
        	generateLadder(start, end, children, ladder, ladders);
        }
        return ladders;
    }
private:
	bool searchLadder(unordered_set<string> &startWord, unordered_set<string> &endWord, unordered_map<string, vector<string>> &children, unordered_set<string>&wordList, bool flip){
		flip = !flip;
		if (startWord.empty() || endWord.empty()) return false;
		if (startWord.size() > endWord.size()) return searchLadder(endWord, startWord, children, wordList, flip);
		for (auto i : startWord) wordList.erase(i);
		for (auto i : endWord) wordList.erase(i);
		unordered_set<string> intermediate;
		bool done = false;
		for (auto word : startWord){
			int n = word.length();
			string temp = word;
			for (int i = 0; i < n; i ++){
				char letter = word[i];
				for (int j = 0; j < 26; j ++){
					word[i] = 'a' + j;
					if (endWord.find(word) != endWord.end()){
						done = true;
						flip ? children[word].push_back(temp) : children[temp].push_back(word);
					}
					else if (wordList.find(word) != wordList.end()){
						intermediate.insert(word);
						flip ? children[word].push_back(temp) : children[temp].push_back(word);
					}
				}
				word[i] = letter;
			}
		}
		return done || searchLadder(endWord, intermediate, children, wordList, flip);		
	}
	void generateLadder(string start, string end, unordered_map<string, vector<string>> &children, vector<string> &ladder, vector<vector<string>> &ladders){
		if (start == end){
			ladders.push_back(ladder);
			return;
		}
		for (string i : children[start]){
			ladder.push_back(i);
			generateLadder(i, end, children, ladder, ladders);
			ladder.pop_back();
		}
	}
};
