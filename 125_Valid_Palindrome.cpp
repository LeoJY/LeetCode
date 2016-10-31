//125. Valid Palindrome
//Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.
#include <iostream>
#include <string>
#include <cctype>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
    	int i = 0, j =s.size() - 1;
    	while (i < j){
    		while (!isalnum(s[i]) && i < j) i++;
    		while (!isalnum(s[j]) && i < j) j--;
    		if ( tolower(s[i++]) != tolower(s[j--])) return false;
    	}
    	return true;
    }
};


int main(){
	Solution testCase;
	cout << "please input the string" << endl;
	string testString;
	getline(cin, testString);
	bool testResult = testCase.isPalindrome(testString);
	cout << "the result is " << (testResult ? "True" : "False") << endl;
	return 0;
}

