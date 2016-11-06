//70. Climbing Stairs
//You are climbing a stair case. It takes n steps to reach to the top.
//Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
#include <iostream>

using namespace std;

class Solution {
public:
    int climbStairs(int n) {
    	if (n < 3) return n;
    	int a = 1, b = 2;
    	for (int i = 3; i <= n; i++){
    		int temp = a + b;
    		a = b;
    		b = temp;
    	}
    	return b;
    }
};

int main(){
	Solution testCase;
	cout << "please intput the testInteger" << endl;
	int testInteger;
	cin >> testInteger;
	int testResult = testCase.climbStairs(testInteger);
	cout << "the result is " << testResult << endl;
	return 0;
}