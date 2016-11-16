//260. Single Number III
//Given an array of numbers nums, in which exactly two elements appear only once and all the other elements appear exactly twice. Find the two elements that appear only once.
//Note:
//The order of the result is not important. So in the above example, [5, 3] is also correct.
//Your algorithm should run in linear runtime complexity. Could you implement it using only constant space complexity?
#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
    	int temp = 0;
    	vector<int> result(2, 0);
    	for (auto i : nums) temp ^= i;
    	temp &= (-temp);
    	for (auto j : nums){
    		if (j & temp) result[0] ^= j;
    		else result[1] ^= j;
    	}
    	return result;
    }
};

int main(){
	Solution testCase;
	string testString;
	int temp;
	vector<int> testVec;
	cout << "please input the test numbers" << endl;
	getline(cin, testString);
	istringstream cinstr(testString);
	while (cinstr >> temp) testVec.push_back(temp);
	vector<int> testResult = testCase.singleNumber(testVec);
	cout << "the result is " << endl;
	for (auto i : testResult) cout << i << '\t';
	cout << endl;
	return 0;
}