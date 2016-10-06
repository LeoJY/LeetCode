//75. Sort Colors
//Given an array with n objects colored red, white or blue, sort them so that objects of the same color are adjacent, with the colors in the order red, white and blue.
//Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.

#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
	void sortColors(vector<int>& nums) {
		int n = nums.size();
		int zero = 0;
		int two = n - 1;
		for (int i = 0; i < two; ++i)
		{
			while (nums[i] == 0) swap(nums[i], nums[zero++]);
			while (nums[i] == 2) swap(nums[i], nums[two--]);
		}
	}
};

int main(){
	Solution testcase;
	vector<int> testvector;
	int input;
	cout << "please input the array (EOF = -9999): " << endl;
	while (cin >> input && input != -9999){
		testvector.push_back(input);
	}
	testcase.sortColors(testvector);
	for (int i = 0; i < testvector.size(); ++i)
	{
		cout << testvector[i] << '\t';
	}
	cout << endl;
	return 0;
}