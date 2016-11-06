//213. House Robber II
//Note: This is an extension of House Robber.
//After robbing those houses on that street, the thief has found himself a new place for his thievery so that he will not get too much attention. This time, all houses at this place are arranged in a circle. That means the first house is the neighbor of the last one. Meanwhile, the security system for these houses remain the same as for those in the previous street.
//Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.
#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() < 2) return (nums.empty() ? 0 : nums[0]);
    	return max(robber(nums, 0, nums.size() - 2), robber(nums, 1, nums.size() - 1));
    }
private:
	int robber(vector<int>& nums, int low, int high){
    	int x = 0, y = 0;
    	for (int i = low; i <= high; i++){
    		int temp = max(y + nums[i], x);
    		y = x;
    		x = temp;
    	}
    	return x;
	}
};   

int main(){
	Solution testcase;
	string testString;
	vector<int> testVector;
	cout << "please input the testString" << endl;
	getline(cin, testString);
	istringstream cinstr(testString);
	int temp;
	while(cinstr >> temp){
		testVector.push_back(temp);
	}
	int testresult = testcase.rob(testVector);
	cout << "the result is " << testresult << endl;
	return 0;
}