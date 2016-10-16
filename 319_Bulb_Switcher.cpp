//319. Bulb Switcher
//There are n bulbs that are initially off. You first turn on all the bulbs. Then, you turn off every second bulb. On the third round, you toggle every third bulb (turning on if it's off or turning off if it's on). For the ith round, you toggle every i bulb. For the nth round, you only toggle the last bulb. Find how many bulbs are on after n rounds.

#include <iostream>
#include <cmath>

using namespace std;

class Solution {
public:
    int bulbSwitch(int n) {
    	return sqrt(n);
    }
};

int main(){
	Solution testcase;
	int testnum;
	cout << "please input the test number" << endl;
	cin >> testnum;
	int testresult = testcase.bulbSwitch(testnum);
	cout << "the result is " << testresult << endl;
	return 0;
}