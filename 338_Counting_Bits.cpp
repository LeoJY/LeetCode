//338. Counting Bits
//Given a non negative integer number num. For every numbers i in the range 0 ≤ i ≤ num calculate the number of 1's in their binary representation and return them as an array.
//Follow up:
//It is very easy to come up with a solution with run time O(n*sizeof(integer)). But can you do it in linear time O(n) /possibly in a single pass?
//Space complexity should be O(n).
//Can you do it like a boss? Do it without using any builtin function like __builtin_popcount in c++ or in any other language.
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> countBits(int num) {
    	vector<int> result(num + 1, 0);
    	for (int i = 1; i <= num; i++){
    		result[i] = result[i >> 1] + (i & 1);
    	}
    	return result;
    }
};

int main(){
	Solution testcase;
	int testInt;
	cout << "please input a testInt" << endl;
	cin >> testInt;
	vector<int> testResult = testcase.countBits(testInt);
	cout << "the result is" << endl;
	for (auto i : testResult) cout << i << " ";
	cout << endl;
	return 0;
}
