//409. Longest Palindrome
//Given a string which consists of lowercase or uppercase letters, find the length of the longest palindromes that can be built with those letters.
//This is case sensitive, for example "Aa" is not considered a palindrome here.
//Note:
//Assume the length of given string will not exceed 1,010.

#include <iostream>

using namespace std;

class Solution {
public:
    int longestPalindrome(string s) {
    	int charNum[256] = {0};
    	int result = 0;
    	for (auto i : s){
    		if (charNum[i] == 1){
    			result += 2;
    			charNum[i] --;
    		}
    		else charNum[i] ++;
    	}
    	return result == s.size()? result : result + 1;
    }
};

int main(){
	Solution testCase;
	string testString;
	cout << "please input the string" << endl;
	getline(cin, testString);
	int testResult = testCase.longestPalindrome(testString);
	cout << "the result is " << testResult << endl;
	return 0;
}