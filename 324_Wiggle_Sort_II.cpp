//324. Wiggle Sort II
//Given an unsorted array nums, reorder it such that nums[0] < nums[1] > nums[2] < nums[3]....
//Note:
//You may assume all input has valid answer.
//Follow Up:
//Can you do it in O(n) time and/or in-place with O(1) extra space?
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

class Solution {
public:
	void wiggleSort(vector<int>& nums) {
		if (nums.size() <= 1) return;
		int n = nums.size();
		auto mid = nums.begin() + n / 2;
		nth_element(nums.begin(), mid, nums.end());
		int midval = *mid;
		int first = 0, midpoint = 0, last = n - 1;
		auto map = [n](int i){
			return (2 * i + 1) % (n | 1);
		};
		while (midpoint <= last){
			if(nums[map(midpoint)] < midval){
				swap(nums[map(midpoint)], nums[map(last)]);
				last --;
			}
			else if (nums[map(midpoint)] > midval){
				swap(nums[map(midpoint)], nums[map(first)]);
				first ++;
				midpoint ++;
			}
			else midpoint ++;
		}
	}
};


int main(){
	Solution testCase;
	int temp;
	string testString;
	vector<int> testVec;
	cout << "please input the num, seperate with space, end with space" << endl;
	getline(cin, testString);
	istringstream cinstr1(testString);
	while (cinstr1 >> temp){
		testVec.push_back(temp);
	}
	testCase.wiggleSort(testVec);
	for (auto i : testVec) cout << i << '\t';
	cout << endl;
	return 0;
}






