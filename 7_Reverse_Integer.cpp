//7. Reverse Integer
//Reverse digits of an integer.

#include <iostream>

using namespace std;

class Solution {
public:
    int reverse(int x) {
        signed long ans = 0;
        for (; x != 0 ; x /= 10) { ans = ans * 10 + x % 10; }
        return (ans < INT_MIN || INT_MAX < ans) ? 0 : ans;
	}
};

int main(){
	Solution testcase;
	cout << "please input the integer" << endl;
	long int testinteger;
	cin >> testinteger;
	int testresult = testcase.reverse(testinteger);
	cout << "the result is " << endl << testresult << endl;
	return 0;
}

