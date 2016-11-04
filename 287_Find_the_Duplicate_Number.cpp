//287. Find the Duplicate Number
//Given an array nums containing n + 1 integers where each integer is between 1 and n (inclusive), prove that at least one duplicate number must exist. Assume that there is only one duplicate number, find the duplicate one.
//Note:
//You must not modify the array (assume the array is read only).
//You must use only constant, O(1) extra space.
//Your runtime complexity should be less than O(n2).
//There is only one duplicate number in the array, but it could be repeated more than once.
#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums){
    	if (nums.size() < 2) return -1;
    	int slow = nums[0];
    	int fast = nums[nums[0]];
    	while(fast != slow){
    		slow = nums[slow];
    		fast = nums[nums[fast]];
    	}
    	fast = 0;
    	while(fast != slow){
    		slow = nums[slow];
    		fast = nums[fast];
    	}
    	return slow;
    }
};

int main(){
	Solution testcase;
	string testString;
	vector<int> testVec;
	cout << "please input the test vector, seperate by space, end by enter" << endl;
	getline(cin, testString);
	istringstream cinstr(testString);
	int temp;
	while (cinstr >> temp){
		testVec.push_back(temp);
	}
	int testResult = testcase.findDuplicate(testVec);
	cout << "the result is " << testResult << endl;
	return 0;
}
