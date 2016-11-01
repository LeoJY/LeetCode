//6. ZigZag Conversion
//The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)
//Write the code that will take a string and make this conversion given a number of rows:

#include <iostream>
#include <string>

using namespace std;

class Solution{
public:
    string convert(string s, int numRows) {
    	if (numRows == 1) return s;
    	string result = "";
    	int step1 = 2 * numRows - 2, step2 = 0;
    	int n = s. size();
    	for (int i = 0; i < numRows; ++i)
    	{
    		int pos = i;
    		if (pos < n) result += s[pos];
    		else return result;
    		while(1){
    			pos += step1;
    			if (pos >= n) break;
    			else if (step1) result += s[pos];
    			pos += step2;
    			if (pos >= n) break;
    			else if (step2) result += s[pos];
    		}
    		step1 -= 2;
    		step2 += 2;
    	}
    	return result;
    }
};


int main(){
	Solution testcase;
	int testInteger;
	string testString;
	cout << "please input the string" << endl;
	cin >> testString;
	cout << "please input the integer" << endl;
	cin >> testInteger;
	string testResult = testcase.convert(testString, testInteger);
	cout << "the result is " << testResult << endl;
	return 0;
}