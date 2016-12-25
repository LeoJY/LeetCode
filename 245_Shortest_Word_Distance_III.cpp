//245. Shortest Word Distance III
//This is a follow up of Shortest Word Distance. The only difference is now word1 could be the same as word2.
//Given a list of words and two words word1 and word2, return the shortest distance between these two words in the list.
//word1 and word2 may be the same and they represent two individual words in the list.
//Note:
//You may assume word1 and word2 are both in the list.


class Solution {
public:
    int shortestWordDistance(vector<string>& words, string word1, string word2) {
        int n = words.size();
        int distance = INT_MAX;
        int index1 = -1, index2 = -1;
        for (int i = 0; i < n; i++){
        	if (words[i] == word1) index1 = i;
        	if (words[i] == word2){
        		if (word1 == word2) index1 = index2;
        		index2 = i;
        	}
        	if (index1 != -1 && index2 != -1) distance = min (distance, abs(index1 - index2));
        }
        return distance;
    }
};

