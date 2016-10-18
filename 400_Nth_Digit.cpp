//400. Nth Digit
//Find the nth digit of the infinite integer sequence 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ...
//Note:
//n is positive and will fit within the range of a 32-bit signed integer (n < 231).

#include <iostream>
#include <cmath>

using namespace std;

class Solution {
private:
    int find(int n, int p){
    	if (n > 9 * p * pow (10, p - 1)) return find(n - 9 * p * pow (10, p - 1), p + 1);
    	else {
    		int x = (n - 1) / p + pow (10, p - 1);
    		int k = (n - 1) % p;
    		return  (x / (int) pow (10, p - 1 - k)) % 10;
    	}
    }
public:    
    int findNthDigit(int n) {
    	return find(n , 1);
    }
};

int main(){
	Solution testCase;
	int testNumber;
	cout << "please input the testNumber" << endl;
	cin >> testNumber;
	int testResult = testCase.findNthDigit(testNumber);
	cout << "the result is " << testResult << endl;
	return 0;
}