//136. Single Number
//Given an array of integers, every element appears twice except for one. Find that single one.
//Note:
//Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
    	int result = 0;
    	for (int i = 0; i < nums.size(); ++i)
    	{
    		result ^= nums[i];
    	}
    	return result;
    }
};

int main(){
	Solution testCase;
	vector<int> testVector;
	cout << "please input the testVector (EOF = -9999)" << endl;
	int inputNum;
	while (cin >> inputNum && inputNum != -9999){
		testVector.push_back(inputNum);
	}
	int testResult = testCase.singleNumber(testVector);
	cout << "the result is " << testResult << endl;
	return 0;
}