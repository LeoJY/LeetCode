//198. House Robber
//You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security system connected and it will automatically contact the police if two adjacent houses were broken into on the same night.
//Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.
#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
    	int x = 0, y = 0;
    	for (int i = 0; i < nums.size(); i++){
    		if (i % 2 == 0) x = max(x + nums[i], y);
    		else y = max(y + nums[i], x);
    	}
    	return max(x, y);
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