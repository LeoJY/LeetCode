//5. Longest Palindromic Substring
//Given a string S, find the longest palindromic substring in S. You may assume that the maximum length of S is 1000, and there exists one unique longest palindromic substring.
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
    	if (s.size() < 2) return s;
    	int len = s. size(), max_start = 0, max_len = 1, left, right, start = 0;
    	for (; start < len && len - start > max_len / 2;){
    		left = start;
    		right = start;
    		while (right < len - 1 && s[right] == s[right + 1]) right ++;
    		start = right + 1;
    		while (right < len - 1 && left > 0 && s[left - 1] == s[right + 1]){
    			left --;
    			right ++;
    		}
    		if (right - left + 1 > max_len){
    			max_len = right - left + 1;
    			max_start = left;
    		}
    	}
    	return s.substr(max_start, max_len);
    }
};

int main(){
	Solution testCase;
	cout << "please input the string" << endl;
	string testString;
	getline(cin, testString);
	string testResult = testCase.longestPalindrome(testString);
	cout << "the result is " << testResult << endl;
	return 0;
}