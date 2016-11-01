//20. Valid Parentheses
//Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
//The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.

#include <iostream>
#include <stack>
#include <unordered_map>
#include <string>

using namespace std;

class Solution{
public:
	bool isValid(string s) {
		stack<char> temp;
		unordered_map<char, char> charPair = {{')','('}, {']', '['}, {'}', '{'}};
		for (int i = 0; i < s.size(); i++){
			if (s[i] == '(' || s[i] == '[' || s[i] == '{') temp.push(s[i]);
			else if (s[i] == ')' || s[i] == ']' || s[i] == '}'){
				if (!temp.empty() && temp.top() == charPair[s[i]]) temp.pop();
				else return false;
			}

		}
		return temp.empty();
	}
};



int main(){
	Solution testCase;
	cout << "please input the string" << endl;
	string testString;
	getline(cin, testString);
	bool testResult = testCase.isValid(testString);
	cout << "the result is " << (testResult ? "True" : "False") << endl;
	return 0;
}