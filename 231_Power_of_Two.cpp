//231. Power of Two
//Given an integer, write a function to determine if it is a power of two.

#include <iostream>

using namespace std;

class Solution {
public:
    bool isPowerOfTwo(int n) {
    	return n > 0 &&  (n & (n - 1)) == 0;
    }
};

int main(){
	Solution testCase;
	int testNumber;
	cout << "please input the test number" << endl;
	cin >> testNumber;
	bool testResult = testCase.isPowerOfTwo(testNumber);
	cout << "the result is " << (testResult ? "Ture" : "False") << endl;
	return 0;
}
