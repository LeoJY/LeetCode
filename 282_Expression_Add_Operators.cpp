//282. Expression Add Operators
//Given a string that contains only digits 0-9 and a target value, return all possibilities to add binary operators (not unary) +, -, or * between the digits so they evaluate to the target value.

class Solution {
public:
	vector<string> addOperators(string num, int target) {
    	vector<string> result;
    	if (num.empty()) return result;
    	for (int i = 0; i < num.size(); i ++){
    		string t = num.substr(0, i + 1);
    		long temp = stol(t);
    		if (to_string(temp) != t) continue;
    		dfs(result, num, target, t, temp, temp, i + 1, '#');
    	}
    	return result;
    }
private:
	void dfs(vector<string>& result, string num, int target, string path, long sum, long curSum, int index, char op){
		if (index == num.size()){
			if (sum == target) result.push_back(path);
			return;
		}
		else{
			for (int j = index; j < num.size(); j ++){
				string t = num.substr(index, j + 1 - index);
				long temp = stol(t);
				if (to_string(temp) != t) continue;
				dfs(result, num, target, path + "+" + t, sum + temp, temp, j + 1, '+');
				dfs(result, num, target, path + "-" + t, sum - temp, temp, j + 1, '-');
				dfs(result, num, target, path + "*" + t, ((op == '+') ? sum - curSum + curSum * temp : ((op == '-') ? sum + curSum - curSum * temp : sum - curSum + curSum * temp)) , curSum * temp, j + 1, op);
			}
		}
	}
};


