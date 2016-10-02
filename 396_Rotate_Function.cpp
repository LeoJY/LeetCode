//396. Rotate Function
//Given an array of integers A and let n to be its length.
//Assume Bk to be an array obtained by rotating the array A k positions clock-wise, we define a "rotation function" F on A as follow:
//F(k) = 0 * Bk[0] + 1 * Bk[1] + ... + (n-1) * Bk[n-1].
//Calculate the maximum value of F(0), F(1), ..., F(n-1).

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
    	int n = nums.size();
    	int sum = 0;
    	int candidate = 0;
    	int ans = 0;
    	for (int i = 0; i < n; ++i)
    	{
    		sum += nums[i];
    		candidate += i * nums[i];
    	}
    	ans = candidate;
    	for (int j = n -1; j > 0; --j)
    	{
    		candidate += sum - n * nums[j];
    		ans = max(ans, candidate);
    	}
    	return ans;
    }
};

int main()
{
	Solution testcase;

	cout << "input the test case array size:" << endl;
	int testarraysize;
	cin >> testarraysize;

	cout << "input the test case array:" << endl;
	int testarray[testarraysize];
	for (int i = 0; i < testarraysize; ++i)
	{
		cout << "please input the " << i+1 << " element:" << endl;
		cin >>testarray[i];
	}

	//generate the vector
	vector <int> testvector(testarray,testarray + testarraysize); 

	int result = testcase.maxRotateFunction(testvector);
	cout << "The result is: " << result << endl;
	return 0;
}