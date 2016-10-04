//53. Maximum Subarray
//Find the contiguous subarray within an array (containing at least one number) which has the largest sum.
//For example, given the array [-2,1,-3,4,-1,2,1,-5,4],
//the contiguous subarray [4,-1,2,1] has the largest sum = 6.

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
    	int sum = 0, result = INT_MIN;
    	int n = nums.size();
    	for (int i = 0; i < n; ++i)
    	{
    		sum += nums[i];
    		result = max(result, sum);
    		if (sum < 0)
    		{
    			sum = 0;
    		}
    	}
    	return result;
  	}
};


int main()
{
	Solution testcase;
	//input the  array

	vector <int> testvector;
	
	cout << "please input the numbers (EOF = 9999):" << endl;
	
	int input;

	while (cin >> input && input != 9999)
		testvector.push_back(input);

	int testresult = testcase.maxSubArray(testvector);

	cout << "the result is: " << endl << testresult << endl;

	return 0;

}