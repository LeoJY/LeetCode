//258. Add Digits
//Given a non-negative integer num, repeatedly add all its digits until the result has only one digit.

#include <iostream>

using namespace std;

class Solution {
public:
    int addDigits(int num) {
    	return (num - 1) % 9 + 1;
    }
};

int main(){
	Solution testcase;
	int testnum;
	cout << "please input the test number" << endl;
	cin >> testnum;
	int testresult = testcase.addDigits(testnum);
	cout << "the result is " << testresult << endl;
	return 0;
}