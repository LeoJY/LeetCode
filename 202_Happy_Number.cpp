//202. Happy Number
//Write an algorithm to determine if a number is "happy".
//A happy number is a number defined by the following process: Starting with any positive integer, replace the number by the sum of the squares of its digits, and repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1. Those numbers for which this process ends in 1 are happy numbers.

#include <iostream>
//#include <unordered_map>

using namespace std;
/*
class Solution {
public:
    bool isHappy(int n) {
    	unordered_map <int, bool> map;
    	int num = 0;
    	map[n] = true;
    	while (n != 1){
    		while(n){
    			num = (n % 10) * (n % 10);
    			n /= 10;
    		}
    		if (map[num]) break;
    		else map[num] = true;
    		n = num;
    		num = 0;
    	}
    	return n == 1;
    }
};
*/

class Solution {
public:
    bool isHappy(int n) {
    	int slow, fast;
    	slow = fast = n;
    	do{
    		slow = compute(slow);
    		fast = compute(compute(fast));
    	} while(slow != fast);
    	return 1 == slow;
    }
private:
	int compute(int n){
		int num = 0;
		while(n){
			num = (n % 10) * (n % 10);
			n /= 10;
		}
		return num;
	}
};

int main(){
	Solution testCase;
	int testNumber;
	cout << "please input the test number" << endl;
	cin >> testNumber;
	bool testResult = testCase.isHappy(testNumber);
	cout << "the result is: " << (testResult ? "True" : "False")<< endl;
	return 0;
}
