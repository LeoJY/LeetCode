//263. Ugly Number
//Write a program to check whether a given number is an ugly number.
//Ugly numbers are positive numbers whose prime factors only include 2, 3, 5. For example, 6, 8 are ugly while 14 is not ugly since it includes another prime factor 7.
//Note that 1 is typically treated as an ugly number.

#include <iostream>

using namespace std;

class Solution {
public:
    bool isUgly(int num) {
    	for (int i = 2; i < 6; ++i)
    	{
    		while (num % i == 0) num /=i;
    	}
    	return num == 1;
    }
};

int main(){
	Solution testcase;
	int testNum;
	cout << "please input the testNum" << endl;
	cin >> testNum;
	bool testresult = testcase.isUgly(testNum);
	if (testresult) cout << "is Ugly Number" << endl;
	else cout << "is not Ugly Number" << endl;
	return 0;
}

