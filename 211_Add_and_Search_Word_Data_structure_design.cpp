//211. Add and Search Word - Data structure design
//Design a data structure that supports the following two operations:
//void addWord(word)
//bool search(word)
//search(word) can search a literal word or a regular expression string containing only letters a-z or .. A . means it can represent any one letter.
//Note:
//You may assume that all words are consist of lowercase letters a-z.

class TrieNode{
public:
	bool isEnd;
	TrieNode* children[26];
	TrieNode(){
		memset(children, NULL, sizeof(children));
		isEnd = false;
	}
};

class WordDictionary {
public:

	//initialize
	WordDictionary(){
		root = new TrieNode();
	}
    // Adds a word into the data structure.
    void addWord(string word) {
        TrieNode* temp = root;
        for (int i = 0; i < word.size(); i++){
        	if (temp -> children[word[i] - 'a'] == NULL) temp -> children[word[i] - 'a'] = new TrieNode();
        	temp = temp -> children[word[i] - 'a'];
        }
        temp -> isEnd = true;
    }

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word) {
    	char* p = &word[0];
        return find(root, p);
    }
private:
	TrieNode* root;
	bool find(TrieNode* root, char* p){
		TrieNode* temp = root;
		for (int i = 0; p[i]; i++){
			if (temp && p[i] != '.') temp = temp -> children[p[i] - 'a'];
			else if (temp && p[i] == '.'){
				TrieNode* node = temp;
				for (int j = 0; j < 26; j++){
					temp = node -> children[j];
					if (find(temp, p + i + 1)) return true;
				}
			}
			else break;
		}
		return temp && temp -> isEnd;
	}
};

// Your WordDictionary object will be instantiated and called as such:
// WordDictionary wordDictionary;
// wordDictionary.addWord("word");
// wordDictionary.search("pattern")



