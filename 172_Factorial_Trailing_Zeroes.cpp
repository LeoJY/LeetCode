//172. Factorial Trailing Zeroes
//Given an integer n, return the number of trailing zeroes in n!.
//Note: Your solution should be in logarithmic time complexity.

#include <iostream>

using namespace std;

class Solution {
public:
    int trailingZeroes(int n) {
    	int result = 0;
    	while(n){
    		n /= 5;
    		result += n;
    	}
    	return result;
    }
};

int main(){
	Solution testCase;
	int testNumber;
	cout << "please input the test number" << endl;
	cin >> testNumber;
	int testResult = testCase.trailingZeroes(testNumber);
	cout << "the result is: " << testResult << endl;
	return 0;
}
