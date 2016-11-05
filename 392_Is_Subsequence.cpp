//392. Is Subsequence
//Given a string s and a string t, check if s is subsequence of t.
//You may assume that there is only lower case English letters in both s and t. t is potentially a very long (length ~= 500,000) string, and s is a short string (<=100).
//A subsequence of a string is a new string which is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (ie, "ace" is a subsequence of "abcde" while "aec" is not).
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
    	int sp = 0, tp = 0;
    	while(tp < t.size()){
    		if (s[sp] == t[tp]) sp++;
    		tp++;
    	}
    	return sp == s.size();
    }
};

int main(){
	Solution testcase;
	string testS, testT;
	cout << "please input the string s" << endl;
	getline(cin, testS);
	cout << "please input the string t" << endl;
	getline(cin, testT);
	bool testResult = testcase.isSubsequence(testS, testT);
	cout << "the result is " << (testResult ? "True" : "False") << endl;
	return 0;
}