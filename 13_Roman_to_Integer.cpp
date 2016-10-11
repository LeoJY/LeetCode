//13. Roman to Integer
//Given a roman numeral, convert it to an integer.
//Input is guaranteed to be within the range from 1 to 3999.

#include <iostream>

using namespace std;

class Solution {
public:
    int romanToInt(string s) {
    	int n = s.size();
    	int result = 0; 
    	for (int i = 0; i < n; ++i)
    	{
    		switch (s[i]){
    			case 'I':	result += (result >= 5 ? -1 : 1);
    						break;
    			case 'V':	result += 5;
    						break;
    			case 'X':	result += (result >= 50 ? -10 : 10);
    						break;
    			case 'L':	result += 50;
    						break;
    			case 'C':	result += (result >= 500 ? -100 : 100);
    						break;
    			case 'D':	result += 500;
    						break;
    			case 'M':	result += 1000;
    						break;
    			default:	return INT_MAX;
    		}
    	}
    	return result;
    }
};

int main(){
	Solution testcase;
	string teststring;
	cout << "please input the Roman number" << endl;
	getline(cin, teststring);
	int testresult = testcase.romanToInt(teststring);
	if (testresult == INT_MAX) cout << "Invalid Input" << endl;
	else cout << "the result is " << endl << testresult << endl;
	return 0;
}

