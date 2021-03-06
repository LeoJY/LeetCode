//313. Super Ugly Number
//Write a program to find the nth super ugly number.
//Super ugly numbers are positive numbers whose all prime factors are in the given prime list primes of size k. For example, [1, 2, 4, 7, 8, 13, 14, 16, 19, 26, 28, 32] is the sequence of the first 12 super ugly numbers given primes = [2, 7, 13, 19] of size 4.
//Note:
//(1) 1 is a super ugly number for any given primes.
//(2) The given numbers in primes are in ascending order.
//(3) 0 < k ≤ 100, 0 < n ≤ 106, 0 < primes[i] < 1000.

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
    	vector<int> pointer(primes.size(),0);
    	vector<int> uglyNumber(n, INT_MAX);
    	uglyNumber[0] = 1;
    	for (int i = 1; i < n; i++){
    		for (int j = 0; j < primes.size(); j++) uglyNumber[i] = min (uglyNumber[i], uglyNumber[pointer[j]] * primes[j]);
    		for (int j = 0; j < primes.size(); j++) pointer[j] += (uglyNumber[i] == uglyNumber[pointer[j]] * primes[j]);
    	}
    return uglyNumber[n - 1];
    }
};

int main(){
	Solution testcase;
	int testnum;
	vector<int> testvector;
	cout << "please input the test number" << endl;
	cin >> testnum;
	cout << "please input the testvector (EOF = 0)" << endl;
	int temp;
	while (cin >> temp && temp != 0){
		testvector.push_back(temp);
	}
	int testresult = testcase.nthSuperUglyNumber(testnum, testvector);
	cout << "the result is " << testresult << endl;
	return 0;
}