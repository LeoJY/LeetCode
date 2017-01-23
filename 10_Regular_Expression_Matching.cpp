//10. Regular Expression Matching
//Implement regular expression matching with support for '.' and '*'.
//'.' Matches any single character.
//'*' Matches zero or more of the preceding element.

class Solution {
public:
    bool isMatch(string s, string p) {
        int sSize = s.size(), pSize = p.size();
        vector<vector<bool>> result (pSize + 1, vector<bool>(sSize + 1, false));
        result[0][0] = true;
        for (int i = 1; i <= pSize; i ++){
        	result[i][0] = (i > 1) && result[i - 2][0] && (p[i - 1] == '*');
        	for (int j = 1; j <= sSize; j ++){
        		if (p[i - 1] != '*'){
        			result[i][j] = result[i - 1][j - 1] && (p[i - 1] == s[j - 1] || p[i - 1] == '.');
        		}
        		else{
        			result[i][j] = result[i - 2][j] || (p[i - 2] == s[j - 1] || p[i - 2] == '.') && result[i][j - 1];
        		}
        	}
        }
        return result[pSize][sSize];
    }
};
