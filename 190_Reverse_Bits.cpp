//190. Reverse Bits
//Reverse bits of a given 32 bits unsigned integer.
//For example, given input 43261596 (represented in binary as 00000010100101000001111010011100), return 964176192 (represented in binary as 00111001011110000010100101000000).
//Follow up:
//If this function is called many times, how would you optimize it?
//Related problem: Reverse Integer
#include <iostream>
#include <stdint.h>

using namespace std;

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
       n = (n >> 16) | (n << 16);
       n = ((n & 0xff00ff00) >> 8) | ((n & 0x00ff00ff) << 8);
       n = ((n & 0xf0f0f0f0) >> 4) | ((n & 0x0f0f0f0f) << 4);
       n = ((n & 0xcccccccc) >> 2) | ((n & 0x33333333) << 2);
       n = ((n & 0xaaaaaaaa) >> 1) | ((n & 0x55555555) << 1);
       return n;
    }
};

int main(){
	Solution testCase;
	uint32_t testNum;
	cout << "please input the number" << endl;
	cin >> testNum;
	cout << "the input is " << testNum << endl;
	uint32_t testResult = testCase.reverseBits(testNum);
	cout << "the testResult is " << testResult << endl;
	return 0;
}