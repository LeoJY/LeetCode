//137. Single Number II
//Given an array of integers, every element appears three times except for one. Find that single one.
//Note:
//Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
    	int x = 0, y = 0;
    	for (auto i : nums){
    		x = (x ^ i) & ( ~ y);
    		y = (y ^ i) & ( ~ x);
    	}
    	return (x | y);
    }
};

int main(){
	Solution testCase;
	int temp;
	string testString;
	vector<int> testVec;
	cout << "please input the test numbers" << endl;
	getline(cin, testString);
	istringstream cinstr(testString);
	while(cinstr >> temp){
		testVec.push_back(temp);
	}
	int testResult = testCase.singleNumber(testVec);
	cout << "the result is " << testResult << endl;
	return 0;
}
