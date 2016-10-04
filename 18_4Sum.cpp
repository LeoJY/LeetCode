//18. 4Sum
//Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> answer;
        int n = nums.size();
        if (n < 4) return answer;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n - 3; ++i)
        {
        	if (nums[i] + nums[i + 1] + nums[i + 2] + nums[i + 3] > target) break;
        	if (nums[i] + nums[n - 1] + nums[n - 2] + nums[n - 3] < target) continue;
        	if (i > 0 && nums[i] == nums[i - 1]) continue;
        	for (int j = i + 1; j < n - 2; ++j)
        	{
        		if (nums[i] + nums[i + 1] + nums[i + 2] + nums[j] > target) break;
	        	if (nums[i] + nums[n - 1] + nums[n - 2] + nums[j] < target) continue;
	        	if (j - 1 > i && nums[j] == nums[j - 1]) continue;
	        	int left = j + 1, right = n -1;
	        	while (left < right){
	        		if ( left - 1 > j && nums[left] == nums[left - 1]) left++;
                    else if ( right + 1 < n && nums[right] == nums[right + 1]) right--;
                    else {
		        		int sum = nums[i] + nums[j] + nums[left] + nums[right];
			        	if (sum < target) left ++;
			        	else if (sum > target) right--;
			        	else{
			        		answer.push_back({nums[i], nums[j], nums[left], nums[right]});
			        		left++;
			        		right--;
		        		}
		        	}
	        	}
	        }
        }
        return answer;
    }
};


int main()
{
	Solution testcase;
	//input the array
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

	cout << "please input the target value: " << endl;
	int testtarget;
	cin >> testtarget;

	//generate the vector
	vector <int> testvector(testarray,testarray + testarraysize); 

	//call the function
	vector<vector<int>> testresult = testcase.fourSum(testvector, testtarget);

	for (int i = 0; i < testresult.size(); ++i)
	{
		for (int j = 0; j < testresult[i].size(); ++j)
		{
			cout << testresult[i][j] << '\t';
		}
		cout << endl;
	}
 
	return 0;
}