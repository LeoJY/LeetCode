//58. Length of Last Word
//Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.
//If the last word does not exist, return 0.
//Note: A word is defined as a character sequence consists of non-space characters only.

#include <iostream>
#include <sstream>

using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
    	istringstream cinstr(s);
    	int result = 0;
    	string temp;
    	while(getline(cinstr, temp, ' ')){
    		if (!temp.empty()) result = temp.size();
    	}
    	return result;
    }
};

int main(){
	Solution testCase;
	string testString;
	cout << "please input the testString" << endl;
	getline(cin, testString);
	int testResult = testCase.lengthOfLastWord(testString);
	cout << testResult << endl;
	return 0;
}
