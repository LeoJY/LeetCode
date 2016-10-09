//209. Minimum Size Subarray Sum
//Given an array of n positive integers and a positive integer s, find the minimal length of a subarray of which the sum ≥ s. If there isn't one, return 0 instead.

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
    	int sum = 0, start = 0, min_len = INT_MAX;
    	for (int i = 0; i < nums.size(); ++i)
    	{
    		sum += nums[i];
    		while (sum > s){
    			min_len = min(min_len, i - start + 1);
    			sum -= nums[start++];
    		}
    	}
    	return min_len == INT_MAX? 0 : min_len;
    }
};

int main(){
	Solution testcase;
	int testtarget;
	vector<int> testvector;
	int input;
	cout << "please input the test target" << endl;
	cin >> testtarget;
	cout << "please input the test vector(EOF = -9999): " << endl;
	while(cin >> input && input != -9999){
		testvector.push_back(input);
	}
	int testresult = testcase.minSubArrayLen(testtarget, testvector);
	cout << "the result is: " << testresult << endl;
	return 0;
}