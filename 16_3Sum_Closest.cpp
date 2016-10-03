//16. 3Sum Closest
//Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target. Return the sum of the three integers. You may assume that each input would have exactly one solution.

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
    	int result, n = nums.size(), min = 2147483647;
    	if (n < 3) return 2147483647;
    	sort(nums.begin(), nums.end());
    	for (int i = 0; i < n; ++i)
    	{
    		if (i == 0 || nums[i] != nums[i - 1])
    		{
    			int j = i + 1, k = n - 1;
    			while (j < k){
    				if (j - 1 > i && nums[j] == nums[j - 1]) j++;
    				else if (k + 1 < n && nums[k] == nums[k + 1]) k--;
    				else {
    					int sum = nums[i] + nums[j] + nums[k];
    					if (sum > target) k--;
    					else if (sum < target) j++;
    					else return sum;
    					if (abs(sum - target) < min)
    					{
    						min = abs(sum - target);
    						result = sum;
    					}
    				}
    			}
    		}
    	}
    	return result;
    }
};

int main()
{
	Solution testcase;
	//input the array

	cout << "input the target value: " << endl;
	int testtarget;
	cin >> testtarget;

	cout << "input the test case array size:" << endl;
	int testarraysize;
	cin >> testarraysize;

	cout << "input the test case array:" << endl;
	int testarray[testarraysize];
	for (int i = 0; i < testarraysize; ++i)
	{
		cout << "please input the " << i+1 << " element:" << endl;
		cin >>testarray[i];
	}

	//generate the vector
	vector <int> testvector(testarray,testarray + testarraysize); 

	//call the twoSum function
	int testresult = testcase. threeSumClosest(testvector, testtarget);
	if (testresult != 2147483647)
	{
		cout << "the result is: " << testresult << endl;
	}
	else
	{
	 	cout << "something wrong!" << endl;
	}
	
 
	return 0;
}