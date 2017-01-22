//301. Remove Invalid Parentheses
//Remove the minimum number of invalid parentheses in order to make the input string valid. Return all possible results.
//Note: The input string may contain letters other than the parentheses ( and ).

//
class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        vector<string> result;
        helper(s, result, 0, 0, vector<char>{'(', ')'});
        return result;
	}
private:
	void helper(string s, vector<string>& result, int last_i, int last_j, vector<char> flag){
		for (int i = last_i, count = 0; i < s.size(); i++){
			if (s[i] != flag[0] && s[i] != flag[1]) continue;
			else if (s[i] == flag[0]) count ++;
			else count --;
			if (count < 0){
				for (int j = last_j; j <= i; j ++){
					if (s[j] == flag[1] && (j == last_j || s[j - 1] != flag[1])){
						string t = s.substr(0, j) + s.substr(j + 1);
						helper(t, result, i, j, flag);
					}
				}
				return;
			}
		}
		string t = s;
		reverse(t.begin(), t.end());
		if (flag[0] == '('){
			helper(t, result, 0, 0, vector<char>{')' , '('});
		}
		else result.push_back(t);
	}
};


//DFS
class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        unordered_set<string> result;
        int removeL = 0, removeR = 0;
        for (auto i : s){
        	if (i == '(') removeL ++;
        	else if (i == ')'){
        		if (removeL > 0) removeL --;
        		else removeR ++;
        	}
        }
        helper(s, result, removeL, removeR, 0, 0, "");
        return vector<string>(result.begin(), result.end());
    }
private:
	void helper(string& s, unordered_set<string>& result, int removeL, int removeR, int pair, int index, string temp){
		if (index == s.size()){
			if (removeL == 0 && removeR == 0 && pair == 0) result.insert(temp);
			return;
		}
		if (s[index] != '(' && s[index] != ')') helper(s, result, removeL, removeR, pair, index + 1, temp + s[index]);
		else{
			if (s[index] == '('){
				if (removeL > 0) helper(s, result, removeL - 1, removeR, pair, index + 1, temp);
				helper(s, result, removeL, removeR, pair + 1, index + 1, temp + s[index]);
			}
			else{
				if (removeR > 0) helper(s, result, removeL, removeR - 1, pair, index + 1, temp);
				if (pair > 0) helper(s, result, removeL, removeR, pair - 1, index + 1, temp + s[index]);
			}
		}
	}
};

