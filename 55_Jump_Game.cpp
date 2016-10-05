//55. Jump Game
//Given an array of non-negative integers, you are initially positioned at the first index of the array.
//Each element in the array represents your maximum jump length at that position.
//Determine if you are able to reach the last index.
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
    	int n = nums.size();
    	int maxreach = 0;
    	int i = 0;
    	for (; i < n && maxreach < n && maxreach >= i; ++i)
    	 {
    	 	maxreach = max(maxreach, i + nums[i]);
    	 } 
    	 return maxreach >= n - 1;
    }
};

int main()
{
	Solution testcase;
	int input;
	vector<int> testvector;
	cout << "please input the vector (EOF=-9999)" << endl;
	while ((cin >> input) && input != -9999)
    testvector.push_back(input);
	bool result = testcase.canJump(testvector);
	if (result) cout << "you are able to reach the last index" << endl;
	else cout << "you are not able to reach the last index" << endl;
	return 0;
}