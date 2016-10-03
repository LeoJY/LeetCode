//15. 3Sum
//Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
    	vector<vector<int>> answer;
        int n = nums.size();
        if ( n < 3) return answer;
        int target = 0;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n - 2; ++i){
        	if (nums[i] + nums[i + 1] + nums[i + 2] > target) break;
        	if (i == 0 || nums[i] != nums[i - 1]){
        		int j = i + 1, k = n - 1;
        		while (j < k){
        			if (j - 1 > i && nums[j] == nums[j-1]){
                        j++;
                    }
                    else if (k + 1 < n && nums[k] == nums[k+1]){
                        k--;
                    }
                    else{
	        			int sum = nums[i] + nums[j] + nums[k];
	        			if (sum > target) k--;
	        			else if (sum < target) j++;
	        			else {
	        				answer.push_back({nums[i], nums[j], nums[k]});
	        				j++;
	        				k--;
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

	//generate the vector
	vector <int> testvector(testarray,testarray + testarraysize); 

	//call the twoSum function
	vector<vector<int>> testresult = testcase.threeSum(testvector);

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