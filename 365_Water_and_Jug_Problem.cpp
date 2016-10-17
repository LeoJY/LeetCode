//365. Water and Jug Problem
//You are given two jugs with capacities x and y litres. There is an infinite amount of water supply available. You need to determine whether it is possible to measure exactly z litres using these two jugs.
//If z liters of water is measurable, you must have z liters of water contained within one or both buckets by the end.
//Operations allowed:
//Fill any of the jugs completely with water.
//Empty any of the jugs.
//Pour water from one jug into another till the other jug is completely full or the first jug itself is empty.

#include <iostream>

using namespace std;

class Solution {
public:
    bool canMeasureWater(int x, int y, int z) {
    	return z == 0 || ((z <= (long int) x + y) && (z % gcd(x, y) == 0));
    }
private:
	int gcd(int x, int y){
		if (x > y) return gcd(y, x);
		while (x != 0){
			y %= x;
			return gcd(y, x);
		}
		return y;
	}
};

int main(){
	Solution testCase;
	int testNumber1, testNumber2, testTarget;
	cout << "please input the testNumber1 & testNumber2 " << endl;
	cin >> testNumber1 >> testNumber2;	
	cout << "please input the testTarget" << endl;
	cin >> testTarget;
	bool testResult = testCase.canMeasureWater(testNumber1, testNumber2, testTarget);
	if (testResult) cout << "it is possible to measure exactly z litres using these two jugs" << endl;
	else cout << "it is impossible to measure exactly z litres using these two jugs" << endl;
	return 0;
}