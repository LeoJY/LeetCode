//397. Integer Replacement
//Given a positive integer n and you can do operations as follow:
//If n is even, replace n with n/2.
//If n is odd, you can replace n with either n + 1 or n - 1.
//What is the minimum number of replacements needed for n to become 1?

#include <iostream>

using namespace std;

class Solution {
public:
    int integerReplacement(int n) {
    	int result = 0;
    	long int m = n;
    	while (m > 3){
    		if (!(m & 1)) m >>= 1;
    		else if (m & 2) m ++;
    		else m --; 
    		result ++;
    	}
    	return result + m - 1;
    }
};

int main(){
	Solution testCase;
	int testNumber;
	cout << "please input the testNumber" << endl;
	cin >> testNumber;
	int testResult = testCase.integerReplacement(testNumber);
	cout << "the result is " << testResult << endl;
	return 0;
}