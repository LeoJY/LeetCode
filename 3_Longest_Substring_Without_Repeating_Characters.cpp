//3. Longest Substring Without Repeating Characters
//Given a string, find the length of the longest substring without repeating characters.
//Note that the answer must be a substring, not a subsequence.

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
    	int start = -1, maxLen = 0;
    	unordered_map<char, int> charMap;
    	for (int i = 0; i < s.size(); i++)
    	{
    		if (charMap.find(s[i]) != charMap.end()){
    			start = max(start, charMap[s[i]]);
    		}
    		charMap[s[i]] = i;
    		maxLen = max(maxLen, i - start);
    	}
    	return maxLen;
    }
};


int main(){
	Solution testCase;
	int temp;
	string testString;
	cout << "please input the testString" << endl;
	cin >> testString;
	int testResult = testCase.lengthOfLongestSubstring(testString);
	cout << "the result is: " << testResult << endl;
	return 0;
}