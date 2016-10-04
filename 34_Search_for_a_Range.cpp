//34. Search for a Range
//Given a sorted array of integers, find the starting and ending position of a given target value.
//Your algorithm's runtime complexity must be in the order of O(log n).

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
    	int low = 0, high = nums.size() - 1;
    	int begin_point, end_point;
    	if (nums[0] > target || nums[high] < target) return vector<int>({-1,-1});
    	while (low < high){
    		int mid = low + (high - low) / 2;
    		if (nums[mid] >= target){
    			high = mid;
    		}
    		else low = mid + 1;
    	}
    	if (nums[low] != target) return vector<int>({-1,-1});
    	begin_point = low;
    	high = nums.size() - 1;
    	while (low < high){
    		int mid = low + (high - low + 1) / 2;
    		if (nums[mid] <= target){
    			low = mid;
    		}
    		else high = mid - 1;
    	}
    	end_point = low;
    	return vector<int>({begin_point, end_point});
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
	vector<int> testresult = testcase.searchRange( testvector, testtarget);

	//show the result
	cout << "the result is: " << endl;
	for(int i=0;i<=testresult.size()-1;i++)
	{
		cout << testresult[i] << "\t" ;
	}
	cout << endl;
	return 0;
}