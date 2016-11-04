//300. Longest Increasing Subsequence
//Given an unsorted array of integers, find the length of longest increasing subsequence.
//Follow up: Could you improve it to O(n log n) time complexity?
#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;
/*
DP:
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
    	int n = nums.size(), result = 1;
    	if (n == 0) return 0;
    	vector<int> dp(n, 1);
    	for (int i = 1; i < n; i++){
    		for (int j = 0; j < i; j++){
    			if (nums[j] < nums[i]) dp[i] = max(dp[i], dp[j] + 1);
    		}
    		result = max(result, dp[i]);
    	}
    return result;
	}
};
*/

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
    	vector<int> res;
    	for (int i = 0; i < nums.size(); i++){
    		auto it = lower_bound(res.begin(), res.end(), nums[i]);
    		if (it == res.end()) res.push_back(nums[i]);
    		else *it = nums[i];
    	}
    	return res.size();
	}
};




int main(){
	Solution testcase;
	string testString;
	vector<int> testVec;
	cout << "please input the test vector, seperate by space, end by enter" << endl;
	getline(cin, testString);
	istringstream cinstr(testString);
	int temp;
	while (cinstr >> temp){
		testVec.push_back(temp);
	}
	int testResult = testcase.lengthOfLIS(testVec);
	cout << "the result is " << testResult << endl;
	return 0;
}
