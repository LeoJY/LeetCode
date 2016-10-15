//171. Excel Sheet Column Number
//Related to question Excel Sheet Column Title
//Given a column title as appear in an Excel sheet, return its corresponding column number.

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int titleToNumber(string s) {
    	int n = s.size();
    	int result = 0;
    	for (int i = 0; i < n; ++i)
    	{
    		result = result * 26 + (s[i] - 'A' + 1);
    	}
    	return result;
    }
};

int main(){
	Solution testCase;
	string testString;
	cout << "please input the test string" << endl;
	cin >> testString;
	int testResult = testCase.titleToNumber(testString);
	cout << "the result is: " << testResult << endl;
	return 0;  
}