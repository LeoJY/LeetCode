//22. Generate Parentheses
//Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
    	vector<string> result;
    	helper(result, "", n , 0);
    	return result;
    }
private:
	void helper(vector<string>& result, string temp, int n, int m){
		if (n == 0 && m == 0){
			result.push_back(temp);
			return;
		}
		if (n > 0) helper(result, temp + "(", n - 1, m + 1);
		if (m > 0) helper(result, temp + ")", n, m - 1);
	}
};

int main(){
	Solution testCase;
	int testInteger;
	cout << "please input the testinteger" << endl;
	cin >> testInteger;
	vector<string> testResult = testCase.generateParenthesis(testInteger);
	for(auto i : testResult) cout << i << endl;
	return 0;
}
