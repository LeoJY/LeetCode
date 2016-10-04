//35. Search Insert Position
//Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.
//You may assume no duplicates in the array.

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
    	int low = 0, high = nums.size() - 1;
    	if (nums[low] > target) return 0;
    	else if (nums[high] < target) return high + 1;
    	else{
    		while (low < high){
    			int mid = low + (high - low) / 2;
    			if (nums[mid] == target) return mid;
    			else if (nums[mid] > target) high = mid;
    			else low = mid + 1;
    		}
    	return low;
    	}
    }
};


int main()
{
	Solution testcase;
	//input the target value and array
	cout << "input the test case target value:" << endl;
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

	//call the function
	int testresult = testcase.searchInsert( testvector, testtarget);

	//show the result
	cout << "the result is: " << endl;
	cout << testresult << endl;
	return 0;
}