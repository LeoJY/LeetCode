//243. Shortest Word Distance
//Given a list of words and two words word1 and word2, return the shortest distance between these two words in the list.
//Note:
//You may assume that word1 does not equal to word2, and word1 and word2 are both in the list.

class Solution {
public:
    int shortestDistance(vector<string>& words, string word1, string word2) {
        int n = words.size();
        int index1 = -1, index2 = -1;
        int result = INT_MAX;
        for (int i = 0; i < n; i++){
        	if (words[i] == word1) index1 = i;
        	if (words[i] == word2) index2 = i;
        	if (index1 != -1 && index2 != -1) result = min(result, abs(index1 - index2));
        }
        return result;
    }
};