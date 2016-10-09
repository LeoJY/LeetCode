//153. Find Minimum in Rotated Sorted Array
//Suppose a sorted array is rotated at some pivot unknown to you beforehand.
//Find the minimum element.
//You may assume no duplicate exists in the array.

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
    	int n = nums.size();
    	int high = n - 1, low =0;
    	while (low < high){
    		if (nums[low] < nums[high]) return low;
    		int mid = low + (high - low) / 2;
    		if (nums[mid] > nums[high]) low = mid + 1;
    		else high = mid;
    	}
    return low;
    }
};

int main(){
	Solution testcase;
	vector<int> testvector;
	int input;
	cout << "please input the test vector(EOF = -9999): " << endl;
	while(cin >> input && input != -9999){
		testvector.push_back(input);
	}
	int testresult = testcase.findMin(testvector);
	cout << "the result is: " << testresult << endl;
	return 0;
}