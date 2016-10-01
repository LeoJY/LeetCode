//189. Rotate Array
//Rotate an array of n elements to the right by k steps.
//For example, with n = 7 and k = 3, the array [1,2,3,4,5,6,7] is rotated to [5,6,7,1,2,3,4].

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if (!nums.empty()) {
            k %= nums.size();
            reverse(nums.begin(), nums.begin() + nums.size() - k);
            reverse(nums.begin() + nums.size() - k, nums.end());
            reverse(nums.begin(), nums.end());
        }
    }
};

int main()
{
	Solution testcase;

	int testarraysize;
	cout << "please input the size of the array" << endl;
	cin >> testarraysize;
	
	int testarray[testarraysize];
	
	for (int i = 0; i < testarraysize; ++i)
	{
		cout << "pleae input the " << i+1 << "th element" << endl;
		cin >> testarray[i];
	}

	vector<int> testvector(testarray,testarray+testarraysize);

	int k;
	cout << "please input the integer K" << endl;
	cin >> k;

	testcase.rotate(testvector, k);

	for (int i = 0; i < testarraysize; ++i)
	{
		cout << testvector[i] << '\t';
	}
	cout << endl;
	return 0;
}