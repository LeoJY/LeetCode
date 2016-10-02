//219. Contains Duplicate II
//Given an array of integers and an integer k, find out whether there are two distinct indices i and j in the array such that nums[i] = nums[j] and the difference between i and j is at most k.

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
public:
	bool containsNearbyDuplicate(vector<int>& nums, int k) {
		int n =nums.size();
		unordered_map<int, int> count;
		if (n < 2 || k < 1) return false;
		for ( int i = 0; i < n; ++i){
			if ( i + 1 - count[nums[i]] < k && count[nums[i]] != 0)
			{
				return true;
			}
			count[nums[i]] = i + 1;
		}
		return false;
	}
};

int main()
{
	Solution testcase;

	cout << "please input the parameter k: " << endl;
	int k;
	cin >> k;

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

	bool result = testcase.containsNearbyDuplicate(testvector, k);

	
	if (result)
	{
		cout << "contains Duplicate" << endl;
	}
	else
	{
		cout << "do not contain Duplicate" << endl;
	}
	

	return 0;
}