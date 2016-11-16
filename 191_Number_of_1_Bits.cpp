//191. Number of 1 Bits
//Write a function that takes an unsigned integer and returns the number of ’1' bits it has (also known as the Hamming weight).
//For example, the 32-bit integer ’11' has binary representation 00000000000000000000000000001011, so the function should return 3.
#include <iostream>
#include <stdint.h>

using namespace std;

class Solution {
public:
    int hammingWeight(uint32_t n) {
    	int count = 0;
    	while (n){
    		n &= (n - 1);
    		count ++;
       }
       return count;
    }
};

int main(){
	Solution testCase;
	uint32_t testNum;
	cout << "please input the test number" << endl;
	cin >> testNum;
	int testResult = testCase.hammingWeight(testNum);
	cout << "the result is " << testResult << endl;
	return 0;
}
