//423. Reconstruct Original Digits from English
//Given a non-empty string containing an out-of-order English representation of digits 0-9, output the digits in ascending order.
//Note:
//Input contains only lowercase English letters.
//Input is guaranteed to be valid and can be transformed to its original digits. That means invalid inputs such as "abc" or "zerone" are not permitted.
//Input length is less than 50,000.

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string originalDigits(string s) {
    	vector<int> numOfDigit(10,0);
    	string result = "";
    	for (char digit : s)
    	{
    		if (digit == 'z') numOfDigit[0] ++;
    		if (digit == 'w') numOfDigit[2] ++;
    		if (digit == 'u') numOfDigit[4] ++;
    		if (digit == 'x') numOfDigit[6] ++;
    		if (digit == 'g') numOfDigit[8] ++;
    		if (digit == 'o') numOfDigit[1] ++;
    		if (digit == 'h') numOfDigit[3] ++;
    		if (digit == 'f') numOfDigit[5] ++;
    		if (digit == 's') numOfDigit[7] ++;
    		if (digit == 'i') numOfDigit[9] ++;
    	}
    	numOfDigit[1] -= (numOfDigit[0] + numOfDigit[2] + numOfDigit[4]);
    	numOfDigit[3] -= numOfDigit[8];
    	numOfDigit[5] -= numOfDigit[4];
    	numOfDigit[7] -= numOfDigit[6];
    	numOfDigit[9] -= (numOfDigit[5] + numOfDigit[6] + numOfDigit[8]);
    	for (int i = 0; i < 10; ++i)
    	{
    		for (int j = 0; j < numOfDigit[i]; ++j)
    		{
    			result.push_back('0' + i);
    		}
    	}
    	return result;
    }
};

int main(){
	Solution testCase;
	int temp;
	string testString;
	cout << "please input the testString" << endl;
	cin >> testString;
	string testResult = testCase.originalDigits(testString);
	cout << "the result is: " << testResult << endl;
	return 0;
}
