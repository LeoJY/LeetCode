//208. Implement Trie (Prefix Tree)
//Implement a trie with insert, search, and startsWith methods.
//Note:
//You may assume that all inputs are consist of lowercase letters a-z.


class TrieNode {
public:
	bool isEnd;
	TrieNode* children[26];
    // Initialize your data structure here.
    TrieNode() {
        memset(children, NULL, sizeof(children));
        isEnd = false;
    }
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string word) {
        TrieNode* temp = root;
        for (int i = 0; i < word.size(); i++){
        	if (temp -> children[word[i] - 'a'] == NULL) temp -> children[word[i] - 'a'] = new TrieNode();
        	temp = temp -> children[word[i] - 'a'];
        }
        temp -> isEnd = true;
    }

    // Returns if the word is in the trie.
    bool search(string word) {
        TrieNode* temp = find(word);
        return temp != NULL && temp -> isEnd;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        return find(prefix) != NULL;
    }

private:
    TrieNode* root;

    TrieNode* find(string word){
    	TrieNode* temp = root;
    	for (int i = 0; i < word.size(); i ++){
    		if (temp -> children[word[i] - 'a'] == NULL) return NULL;
    		temp = temp  -> children[word[i] - 'a'];
    	}
    	return temp;
    }
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");