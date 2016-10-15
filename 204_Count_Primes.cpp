//204. Count Primes
//Count the number of prime numbers less than a non-negative number, n.

#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int countPrimes(int n) {
        vector<bool> prime(n, true);
        prime[0] = prime[1] = false;
        for (int i = 0; i < sqrt(n); ++i){
            if (prime[i]){
                for (int j = i * i; j < n; j += i){
                    prime[j] = false;
                }
            }
        }
        return count(prime.begin(), prime.end(), true);
    }
};

int main(){
	Solution testCase;
	int testNumber;
	cout << "please input the test number" << endl;
	cin >> testNumber;
	int testResult = testCase.countPrimes(testNumber);
	cout << "the result is: " << testResult<< endl;
	return 0;
}


