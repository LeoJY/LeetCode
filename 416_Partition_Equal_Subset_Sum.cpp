//416. Partition Equal Subset Sum
//Given a non-empty array containing only positive integers, find if the array can be partitioned into two subsets such that the sum of elements in both subsets is equal.
//Note:
//Each of the array element will not exceed 100.
//The array size will not exceed 200.
#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

class Solution {
public:
    bool canPartition(vector<int>& nums) {
    	if (nums.empty()) return true;
    	int sum = 0;
    	for (auto i : nums) sum += i;
    	if (sum % 2 != 0) return false;
    	sum /= 2;
    	vector<bool> dp(sum + 1, false);
    	dp[0] = true;
    	for (auto i : nums){
    		for (int j = sum; j >= i; j--){
    			dp[j] = dp[j] || dp[j - i];
    		}
    	}
    	return dp[sum];
    }
};

int main(){
	Solution testCase;
	string testStr;
	cout << "please input the test numbers, seperate with space, end with enter" << endl;
	getline(cin, testStr);
	istringstream cinstr(testStr);
	int temp;
	vector<int> testVector;
	while (cinstr >> temp){
		testVector.push_back(temp);
	}
	bool testResult = testCase.canPartition(testVector);
	cout << "the result is  " << (testResult ? "True" : "False") << endl;
	return 0;
}