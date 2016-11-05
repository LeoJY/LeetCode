//441. Arranging Coins
//You have a total of n coins that you want to form in a staircase shape, where every k-th row must have exactly k coins.
//Given n, find the total number of full staircase rows that can be formed.
//n is a non-negative integer and fits within the range of a 32-bit signed integer.
#include <iostream>
#include <cmath>

using namespace std;

class Solution {
public:
    int arrangeCoins(int n) {
       return floor(-0.5+sqrt((double)2*n+0.25));
   }
};
 
int main(){
	Solution testcase;
	int testInteger, testResult;
	cout << "please input testInteger" << endl;
	cin >> testInteger;
	testResult = testcase.arrangeCoins(testInteger);
	cout << "the result is " << testResult << endl;
	return 0;
}