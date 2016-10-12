//50. Pow(x, n)
//Implement pow(x, n)

#include <iostream>

using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
    	if (n == 0) return 1;
    	if (n < 0){
    		if (n == INT_MIN){
    			if (x == 1.0 || x == -1.0) return 1;
    			else return 0;
    		}
    		n = abs(n);
    		x = 1 / x;
    	}
    	return (n % 2 == 0 ? myPow(x * x, n / 2) : x * myPow(x * x, n / 2));
    }
};

int main(){
	Solution testcase;
	int testx, testn;
	cout << "please input the x and n" << endl;
	cin >> testx >> testn;
	int testresult = testcase.myPow(testx, testn);
	cout << "the result is " << endl << testresult << endl;
	return 0;
}