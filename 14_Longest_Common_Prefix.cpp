//14. Longest Common Prefix
//Write a function to find the longest common prefix string amongst an array of strings.

#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
    	string result = "";
    	if (strs.size() == 0) return result; 
    	for (int index = 0; index < strs[0].size(); result += strs[0][index], index++){
    		for (int i = 0; i < strs.size(); ++i){
    			if (index >= strs[i].size() || strs[0][index] != strs[i][index]) return result;
    		}
    	}
    	return result;
    }
};

int main(){
	Solution testCase;
	cout << "please input the strings, seperate with space, end with enter" << endl;
	string testString, temp;
	getline(cin, temp);
	istringstream cinStr(temp);
	vector<string> testVector;
	while(getline(cinStr, testString, ' ')){
		testVector.push_back(testString);
	}
	string testResult = testCase.longestCommonPrefix(testVector);
	cout << "the result is " << testResult << endl;
	return 0;
}