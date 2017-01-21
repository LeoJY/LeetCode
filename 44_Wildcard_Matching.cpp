//44. Wildcard Matching
//Implement wildcard pattern matching with support for '?' and '*'.

class Solution {
public:
    bool isMatch(string s, string p) { 
        int m = s.size(), n = p.size();
        vector<bool> result(m + 1, false);
        result[0] = true;
        for(int i = 1; i <= n; i ++){
        	bool pre = result[0];
        	result[0] = result[0] && p[i - 1] == '*';
        	for (int j = 1; j <= m; j++){
        		bool temp = result[j];
        		if (p[i - 1] == '*') result[j] = (result[j - 1] || result[j]);
        		else result[j] = pre && (p[i - 1] == s[j - 1] || p[i - 1] == '?');
        		pre = temp;
        	}
        }
        return result[m];
    }
};