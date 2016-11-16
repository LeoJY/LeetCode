//201. Bitwise AND of Numbers Range
//Given a range [m, n] where 0 <= m <= n <= 2147483647, return the bitwise AND of all numbers in this range, inclusive.
#include <iostream>

using namespace std;

class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
    	return n > m ? (rangeBitwiseAnd(m >> 1, n >> 1) << 1) : m;
    }
};

int main(){
	Solution testCase;
	int testNum1, testNum2;
	cout << "please input the testNum1 " << endl;
	cin >> testNum1;
	cout << "please input the testNum2 " << endl;
	cin >> testNum2;
	int testResult = testCase.rangeBitwiseAnd(testNum1, testNum2);
	cout << "the result is " << testResult << endl;
	return 0;
}