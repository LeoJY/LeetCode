//80. Remove Duplicates from Sorted Array II
//Follow up for "Remove Duplicates":
//What if duplicates are allowed at most twice?

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
    	int n = nums.size(), count = 0;
    	for (int i = 2; i < n; i++)
        	if (nums[i] == nums[i - 2 - count]) count++;
        	else nums[i - count] = nums[i];
    return n - count;
	}
};

int main()
{
	Solution testcase;
	int input;
	vector<int> testvector;
	cout << "please input the array (EOF = -9999):" << endl;
	while (cin >> input && input != -9999){
		testvector.push_back(input);
	}
	int result = testcase.removeDuplicates(testvector);
	cout << result << endl;
	return 0;
}