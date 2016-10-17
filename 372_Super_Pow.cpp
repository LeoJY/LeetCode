//372. Super Pow
//Your task is to calculate ab mod 1337 where a is a positive integer and b is an extremely large positive integer given in the form of an array.

#include <iostream>
#include <vector>

using namespace std;
/*
class Solution {
public:
	int superPow(int a, vector<int>& b) {
  	int temp = 0, result = 1;
  	for (int i : b){
  		temp = (temp * 10 + i) % 1140;
  	}
  	a %= 1337;
  	while (temp--) result = (result * a) % 1337; 
  	return result;
  	}
};
*/
class Solution {
public:
 	int superPow(int a, vector<int>& b) {
 		if (b.empty()) return 1;
 		int lastDigit = b.back();
 		b.pop_back();
 		return ((powMod(superPow(a, b), 10) * powMod(a, lastDigit)) % 1337);
	}
private:
	int powMod (int a, int k){
		a %= 1337;
		int result = 1;
		while (k){
			result = (result * a) % 1337;
			k--;
		}
		return result;
	}
};



int main(){
	Solution testCase;
	int testInteger;
	vector<int> testVector;
	cout << "please input the testInteger : " << endl;
	cin >> testInteger;
	cout << "please input the testVector (EOF == -9999) : " << endl;
	int temp;
	while (cin >> temp && temp != -9999){
		testVector.push_back(temp);
	}
	int testResult = testCase.superPow(testInteger, testVector);
	cout << testResult << endl;
	return 0;
}

