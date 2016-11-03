//290. Word Pattern
//Given a pattern and a string str, find if str follows the same pattern.
//Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in str.
//Notes:
//You may assume pattern contains only lowercase letters, and str contains lowercase letters separated by a single space.

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool wordPattern(string pattern, string str) {
    	istringstream strcin(str);
    	string temp;
    	vector<string> word;
    	unordered_map<char, string> p2w;
    	unordered_map<string, char> w2p;
    	while (strcin >> temp) word.push_back(temp);
    	if (pattern.size() != word.size()) return false;
    	for (int i = 0; i < pattern.size(); ++i)
    	{
    		if (w2p[word[i]] == 0 && p2w[pattern[i]] == "")
    		{
    			w2p[word[i]] = pattern[i];
    			p2w[pattern[i]] = word[i];
    		}
    		else if (w2p[word[i]] != pattern[i] && p2w[pattern[i]] != word[i]) return false;
    	}
    	return true;
    }
};

int main(){
	Solution testCase;
	string testPattern, testStr;
	cout << "please input the testPattern" << endl;
	getline(cin, testPattern);	
    cout << testPattern << endl;
	cout << "please input the testStr" << endl;
	getline(cin, testStr);
	bool testResult = testCase.wordPattern(testPattern, testStr);
	cout << (testResult ? "the string matches the pattern" : "the string does not match the pattern") << endl;
	return 0; 
}