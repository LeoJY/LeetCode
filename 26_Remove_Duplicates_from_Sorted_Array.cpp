//26. Remove Duplicates from Sorted Array
//Given a sorted array, remove the duplicates in place such that each element appear only once and return the new length.
//Do not allocate extra space for another array, you must do this in place with constant memory.

Do not allocate extra space for another array, you must do this in place with constant memory.
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) 
    {
        if (nums.empty()) return 0;
        int n = 0;
        for(int i = 0; i <nums.size(); i++)
        {
            if (nums[n] != nums[i])
                nums[++n] = nums[i];
        }
        return n +1;
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

	for (int i = 0; i < testarraysize - 1; ++i)
	{
		if ( testarray[i] > testarray[i + 1]  )
		{
			cout << "Invalid Input!" << endl;
			return -1;
		}
	}

	vector<int> testvector(testarray,testarray + testarraysize);

	int result;

	result = testcase.removeDuplicates(testvector);

	cout << "The result array size is " << result << endl;

	for (int i = 0; i < result ; ++i)
	{
		cout << testvector[i] << '\t';
	}
	cout << endl;

	return 0;
}