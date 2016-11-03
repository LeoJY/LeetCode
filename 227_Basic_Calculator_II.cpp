//227. Basic Calculator II
//Implement a basic calculator to evaluate a simple expression string.
//The expression string contains only non-negative integers, +, -, *, / operators and empty spaces . The integer division should truncate toward zero.
//You may assume that the given expression is always valid.
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

class Solution {
public:
    int calculate(string s) {
    	istringstream cinstr('+' + s + '+' );
    	long long temp = 0, result = 0, n;
    	char op;
    	while(cinstr >> op){
    		if (op == '+' || op == '-'){
    			result += temp;
    			cinstr >> temp;
    			temp *= 44 - op;
    		}
    		else{
    			cinstr >> n;
    			if (op == '*')
                	temp *= n;
            	else
                	temp /= n;
    		}
    	}
    	return result;
    }
};

int main(){
	Solution testcase;
	string testString;
	cout << "please input the test string" << endl;
	getline(cin, testString);
	int testResult = testcase.calculate(testString);
	cout << "the result is " << endl << testResult << endl;
	return 0;
}