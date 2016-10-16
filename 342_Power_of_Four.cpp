//342. Power of Four
//Given an integer (signed 32 bits), write a function to check whether it is a power of 4.
//Follow up: Could you solve it without loops/recursion?

#include <iostream>
#include <cmath>

using namespace std;

class Solution {
public:
    bool isPowerOfFour(int num) {
    	int a = sqrt(num);
    	return num > 0 && a * a == num && (a & (a - 1)) ==0;
    }
};

int main(){
	Solution testcase;
	int testNum;
	cout << "please input the testNum" << endl;
	cin >> testNum;
	bool testresult = testcase.isPowerOfFour(testNum);
	if (testresult) cout << "is PowerOfFour" << endl;
	else cout << "is not PowerOfFour" << endl;
	return 0;
}
