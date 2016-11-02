//91. Decode Ways
//A message containing letters from A-Z is being encoded to numbers using the following mapping:
/*
'A' -> 1
'B' -> 2
...
'Z' -> 26
*/
//Given an encoded message containing digits, determine the total number of ways to decode it.

#include <iostream>
#include <string>

using namespace std;

class Solution {
private:
	bool isValid(char a){
		return (a != '0');
	}
	bool isValid(char a, char b){
		return (a == '1' || (a == '2' && b <= '6'));
	}
public:
    int numDecodings(string s) {
    	if (s.empty() || s[0] == '0') return 0;
    	if (s.size() == 1) return 1;
    	int f1 = 1, f2 = 1, result;
    	for (int i = 1; i < s.size(); ++i){
    		if (isValid(s[i]) && isValid(s[i - 1], s[i])) result = f1 + f2;
            else if (!isValid(s[i]) && isValid(s[i - 1], s[i])) result = f2;
            else if (isValid(s[i]) && !isValid(s[i - 1], s[i])) result = f1;
            else return 0;
            f2 = f1;
            f1 = result;
            result = 0;
    	}
    	return f1;
    }
};


int main(){
	Solution testCase;
	string testString;
	cout << "please input the testString" << endl;
	getline(cin, testString);
	int testResult = testCase.numDecodings(testString);
	cout << testResult << endl;
	return 0;
}
