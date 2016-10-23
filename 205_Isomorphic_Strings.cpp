//205. Isomorphic Strings
//Given two strings s and t, determine if they are isomorphic.
//Two strings are isomorphic if the characters in s can be replaced to get t.
//All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character but a character may map to itself.
#include <iostream>

using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
    	if (s.size() != t.size()) return false;
    	int sCount[256] = {0}, tCount[256] = {0};
    	for (int i = 0; i < s.size(); ++i)
    	{
    		if (sCount[s[i]] != tCount[t[i]]) return false;
    		sCount[s[i]] = tCount[t[i]] = i + 1;
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
	bool testResult = testCase.isIsomorphic(testString1, testString2);
	if (testResult) cout << "is Isomorphic" << endl;
	else cout << "is not Isomorphic" << endl;	
	return 0;
}