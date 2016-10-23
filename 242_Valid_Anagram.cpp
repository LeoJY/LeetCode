//242. Valid Anagram
//Given two strings s and t, write a function to determine if t is an anagram of s.
//Note:
//You may assume the string contains only lowercase alphabets.
//Follow up:
//What if the inputs contain unicode characters? How would you adapt your solution to such case?

#include <iostream>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
    	if (s.size() != t.size()) return false;
    	int charCount[26] = {0};
    	for (int i = 0; i < s.size(); ++i){
    		charCount[s[i] - 'a']++;
    		charCount[t[i] - 'a']--;
    	}
    	for (int i = 0; i < 26; ++i){
    		if(charCount[i] != 0) return false;
    	}
    	return true;
    }
};


int main(){
	Solution testCase;
	string testString1, testString2;
	cout << "please input the testString1" << endl;
	getline(cin, testString1);
	cout << "please input the testString2" << endl;
	getline(cin, testString2);
	bool testResult = testCase.isAnagram(testString1, testString2);
	if (testResult) cout << "is Anagram" << endl;
	else cout << "is not Anagram" << endl;	
	return 0;
}