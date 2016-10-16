//326. Power of Three
//Given an integer, write a function to determine if it is a power of three.
//Follow up:Could you do it without using any loop / recursion?

#include <iostream>
#include <cmath>

using namespace std;

class Solution {
public:
    bool isPowerOfThree(int n) {
    	return fmod(log10(n) / log10(3) , 1) == 0;
    }
};

int main(){
	Solution testcase;
	int testNum;
	cout << "please input the testNum" << endl;
	cin >> testNum;
	bool testResult = testcase.isPowerOfThree(testNum);
	if (testResult) cout << "is power of 3" << endl;
	else cout << "is not power of 3" << endl;
	return 0;
}
