//217. Contains Duplicate
//Given an array of integers, find if the array contains any duplicates. Your function should return true if any value appears at least twice in the array, and it should return false if every element is distinct.

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution{
public:
	bool containsDuplicate(vector<int>& nums){
		int n = nums.size();
		if (n < 2) return false;
		unordered_map<int, int> count;
		for (int i = 0; i < n; ++i)
		{
			if (count[nums[i]] > 0)
			{
				return true;
			}
			count[nums[i]]++;
		}
		return false;
	}
};

int main()
{
	Solution testcase;

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

	bool result = testcase.containsDuplicate(testvector);

	
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