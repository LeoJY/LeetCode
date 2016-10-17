//367. Valid Perfect Square
//Given a positive integer num, write a function which returns True if num is a perfect square else False.
//Note: Do not use any built-in library function such as sqrt.

#include <iostream>

using namespace std;

class Solution {
public:
    bool isPerfectSquare(int num) {
    	int low = 1, high = num;
    	while(low <= high){
    		long int mid = low + (high - low) / 2;
    		if (mid * mid == num) return true;
    		else if (mid * mid > num) high = mid - 1;
    		else low = mid + 1;
   		}
   		return false;
    }
};

int main(){
	Solution testCase;
	int testNumber;
	cout << "please input the testNumber" << endl;
	cin >> testNumber;
	bool testResult = testCase.isPerfectSquare(testNumber);
	if (testResult) cout << "is Perfect Square" << endl;
	else cout << "is not Perfect Square" << endl;
	return 0;
}
