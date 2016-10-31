//344. Reverse String
//Write a function that takes a string as input and returns the string reversed.

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string reverseString(string s) {
    	int j = s.size() - 1;
    	int i = 0;
    	while (i < j) swap(s[i++], s[j--]);
    	return s;
    }
};

int main(){
	Solution testCase;
	cout << "please input the string" << endl;
	string testString;
	getline(cin, testString);
	string testResult = testCase.reverseString(testString);
	cout << "the result is " << testResult << endl;
	return 0;
}
