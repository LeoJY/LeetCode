//33. Search in Rotated Sorted Array
//Suppose a sorted array is rotated at some pivot unknown to you beforehand.
//You are given a target value to search. If found in the array return its index, otherwise return -1.
//You may assume no duplicate exists in the array.
#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
    	int high = nums.size() - 1, low = 0;
    	while (low <= high){
    		int mid = low + (high - low) / 2;
    		if (nums[mid] == target) return mid;
    		else if (nums[mid] > nums[high]){
    			if (target > nums[mid] || target <= nums[high]) low = mid + 1;
    			else high = mid - 1;
    		}
    		else{
    			if (target > nums[mid] && target <= nums[high]) low = mid + 1;
    			else high = mid - 1;
    		}
    	}
    	return -1;
    }
};

int main(){
	Solution testcase;
	int testInt;
	string testString;
	vector<int> testVec;
	cout << "please input the target value." << endl;
	cin >> testInt;
	cin.ignore();
	cout << "please input the test vector, seperate by space, end by enter" << endl;
	getline(cin, testString);
	istringstream cinstr(testString);
	int temp;
	while (cinstr >> temp){
		testVec.push_back(temp);
	}
	int testResult = testcase.search(testVec, testInt);
	cout << "the result is " << testResult << endl;
	return 0;
}