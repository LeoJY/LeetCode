//415. Add Strings
//Given two non-negative numbers num1 and num2 represented as string, return the sum of num1 and num2.
//Note:
//The length of both num1 and num2 is < 5100.
//Both num1 and num2 contains only digits 0-9.
//Both num1 and num2 does not contain any leading zero.
//You must not use any built-in BigInteger library or convert the inputs to integer directly.

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string addStrings(string num1, string num2) {
    	int i = num1.size() - 1;
    	int j = num2.size() - 1;
    	int carry = 0;
    	string result = "";
    	while(i >= 0 || j >= 0 || carry){
    		int temp = 0; 
    		temp+= (i >= 0 ? num1[i] - '0' : 0); i --;
    		temp += (j >= 0 ? num2[j] - '0' : 0); j --;
    		temp += carry;
    		carry = temp / 10;
    		temp %= 10;
    		result = to_string(temp) + result;
    	}
    	return result;
    }
};


int main(){
	Solution testCase;
	int temp;
	string testString1, testString2;
	cout << "please input the testString1" << endl;
	cin >> testString1;
	cout << "please input the testString2" << endl;
	cin >> testString2;
	string testResult = testCase.addStrings(testString1, testString2);
	cout << "the result is: " << testResult << endl;
	return 0;
}

