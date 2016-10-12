//29. Divide Two Integers
//Divide two integers without using multiplication, division and mod operator.
//If it is overflow, return MAX_INT.

#include <iostream>

using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
    	if (divisor == 0 || (dividend == INT_MIN && divisor == -1)) return INT_MAX;
    	int indicator = ((dividend > 0) ^ (divisor > 0)) ? -1 : 1;
    	long int dvd = labs(dividend);
    	long int dvs = labs(divisor);
    	int result = 0;
    	while (dvd >= dvs){
    		long int temp = dvs, multiple = 1;
    		while (dvd >= (temp << 1)){
    			temp <<= 1;
    			multiple <<= 1;
    		}
    		result += multiple;
    		dvd -= temp;
    	}
    return (indicator == 1) ? result : -result;
	}
};

int main(){
    Solution testcase;
    cout << "please input the dividend" << endl;
    int testdividend;
    cin >> testdividend;
    cout << "please input the divisor" << endl;
    int testdivisor;
    cin >> testdivisor;
    int testresult = testcase.divide(testdividend, testdivisor);
    cout << "the result is " << endl << testresult << endl;
    return 0;
}