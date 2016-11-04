//81. Search in Rotated Sorted Array II
//Follow up for "Search in Rotated Sorted Array":
//What if duplicates are allowed?
//Would this affect the run-time complexity? How and why?
//Write a function to determine if a given target is in the array.
#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
    	int high = nums.size() - 1, low = 0;
    	while (low < high){
    		int mid = low + (high - low) / 2;
    		if (nums[mid] == target) return true;
    		else if (nums[mid] > nums[high]){
    			if (target > nums[mid] || target <= nums[high]) low = mid + 1;
    			else high = mid - 1;
    		}
    		else if (nums[mid] < nums[high]){
    			if (target > nums[mid] && target <= nums[high]) low = mid + 1;
    			else high = mid - 1;
    		}
    		else high --;
    	}
    	return (nums[low] == target ? true : false);
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
	cout << "the result is " << (testResult ? "True" : "False") << endl;
	return 0;
}
