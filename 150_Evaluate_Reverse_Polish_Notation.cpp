//150. Evaluate Reverse Polish Notation
//Evaluate the value of an arithmetic expression in Reverse Polish Notation.
//Valid operators are +, -, *, /. Each operand may be an integer or another expression.
#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
    	string s = tokens.back();
    	tokens.pop_back();
    	if (s == "+" || s == "-" || s == "*" || s == "/"){
    		int a = evalRPN(tokens);
    	   	int b = evalRPN(tokens);
    	   	if (s == "+") return b + a;
    	  	else if (s == "-") return b - a;
    	   	else if (s == "*") return b * a;
    	   	else if (s == "/") return b / a;
    	}
    	return stoi(s);
    }
};

int main()
{
	Solution testCase;
	string testString, temp;
	vector<string> testVector;
	cout << "please input the test string, seperate with space, end with enter" << endl;
	getline(cin, testString);
	istringstream cinstr(testString);
	while(cinstr >> temp){
		testVector.push_back(temp);
	}
	int testResult = testCase.evalRPN(testVector);
	cout << "the result is " << testResult << endl;
	return 0;
}