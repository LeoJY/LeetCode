//168. Excel Sheet Column Title
//Given a positive integer, return its corresponding column title as appear in an Excel sheet.

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string convertToTitle(int n) {
    	string result = "";
    	while(n){
    		char temp = (n - 1) % 26 + 'A';
    		result = temp + result;
    		n = (n - 1) / 26;
    	}
    	return result;
    }
};

int main(){
	Solution testcase;
	cout << "please input the test number" << endl;
	int testNumber;
	cin >> testNumber;
	string testResult = testcase.convertToTitle(testNumber);
	cout << "the result is: " << testResult << endl;
	return 0;
}
