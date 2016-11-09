//377. Combination Sum IV
//Given an integer array with all positive numbers and no duplicates, find the number of possible combinations that add up to a positive integer target.
//Follow up:
//What if negative numbers are allowed in the given array?
//How does it change the problem?
//What limitation we need to add to the question to allow negative numbers?
#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
    	vector<int> dp(target + 1);
    	dp[0] = 1;
    	for (int i = 1; i <= target; i++){
    		for (auto j : nums){
    			if (j <= i) dp[i] += dp[i - j];
    		}
    	}
    	return dp[target];
    }
};

int main(){
	Solution testCase;
	string testStr;
	int testInt;
	cout << "please input the testInt" << endl;
	cin >> testInt;
	cin.ignore();
	cout << "please input the test numbers, seperate with space, end with enter" << endl;
	getline(cin, testStr);
	istringstream cinstr(testStr);
	int temp;
	vector<int> testVector;
	while (cinstr >> temp){
		testVector.push_back(temp);
	}
	int testResult = testCase.combinationSum4(testVector, testInt);
	cout << "the result is  " << testResult << endl;
	return 0;
}