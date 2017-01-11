//139. Word Break
//Given a non-empty string s and a dictionary wordDict containing a list of non-empty words, determine if s can be segmented into a space-separated sequence of one or more dictionary words. You may assume the dictionary does not contain duplicate words.


class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size(), cnt = wordDict.size();
        if (n <= 0 || cnt <= 0) return false;
        vector<bool> result(n + 1, false);
        result[0] = true;
        for (int i = 1; i <= n; i++){
        	for (int j = i - 1; j >= 0; j --){
        		if (!result[j]) continue;
        		string temp = s.substr(j, i - j );
        		if (find(wordDict.begin(), wordDict.end(), temp) != wordDict.end()){
        			result[i] = true;
        			break;
        		}
        	}
        }
        return result[n];
    }
};