//264. Ugly Number II
//Write a program to find the n-th ugly number.
//Ugly numbers are positive numbers whose prime factors only include 2, 3, 5. For example, 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 is the sequence of the first 10 ugly numbers.
//Note that 1 is typically treated as an ugly number.

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int nthUglyNumber(int n) {
    	if (n <= 0) return 0;
    	if (n == 1) return 1;
    	vector<int> uglyNum(n);
    	uglyNum[0] = 1;
    	int p2, p3, p5;
    	p2 = p3 = p5 =0;
    	for (int i = 1; i < n; ++i)
    	{
    		uglyNum[i] = min(uglyNum[p2] * 2, min(uglyNum[p3] * 3, uglyNum[p5] * 5));
    		if (uglyNum[p2] * 2 == uglyNum[i]) p2++;
    		if (uglyNum[p3] * 3 == uglyNum[i]) p3++;
    		if (uglyNum[p5] * 5 == uglyNum[i]) p5++;
    	}
    	return uglyNum[n - 1];
    }
};

int main(){
	Solution testcase;
	int testNum;
	cout << "please input the testNum" << endl;
	cin >> testNum;
	int testResult = testcase.nthUglyNumber(testNum);
	cout << "the result is " << testResult << endl;
	return 0;
}
