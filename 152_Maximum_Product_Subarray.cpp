//152. Maximum Product Subarray
//Find the contiguous subarray within an array (containing at least one number) which has the largest product.

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
    	int n = nums.size();
    	int maxs = nums[0];
    	int mins = nums[0];
    	int result = nums[0];
    	for (int i = 1; i < n; ++i)
    	{
    		if (nums[i] < 0) swap(maxs, mins);
    		maxs =max(nums[i], maxs * nums[i]);
    		mins =min(nums[i], mins * nums[i]);
    		result = max(result, maxs);
    	}
    	return result;
    }
};

int main(){
	Solution testcase;
	vector<int> testvector;
	int input;
	cout << "please input the testvector(EOF= -9999) : " << endl;
	while (cin >> input && input != -9999){
		testvector.push_back(input);
	}
	int testresult;
	testresult = testcase.maxProduct(testvector);
	cout << "the result is: " << testresult << endl;
	return 0;
}