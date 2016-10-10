//268. Missing Number
//Given an array containing n distinct numbers taken from 0, 1, 2, ..., n, find the one that is missing from the array.
//Note:
//Your algorithm should run in linear runtime complexity. Could you implement it using only constant extra space complexity?

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
    	int result = 0;
    	for (int i = 0; i < nums.size(); i++)
    	{
    		result ^= nums[i] ^ i;
    	}
    	return result ^ nums.size();
	}
};

int main(){
	Solution testcase;
	vector<int> testvector;
	cout << "please input the testvector(EOF= -9999) :" << endl;
	int input;
	while (cin >> input && input != -9999){
		testvector.push_back(input);
	}
	int testresult;
	testresult = testcase.missingNumber(testvector);
	cout << "the result is: " << endl;
	cout << testresult << endl;
	return 0;
}