//238. Product of Array Except Self
//Given an array of n integers where n > 1, nums, return an array output such that output[i] is equal to the product of all the elements of nums except nums[i].
//Solve it without division and in O(n).

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
    	int n = nums.size();
    	vector<int> result(n,0);
    	result[0] = 1;
    	for (int i = 1; i < n; ++i){
    		result[i] = result[i - 1] * nums[i - 1];
    	}
    	int temp = 1;
    	for (int i = n -2; i >= 0; --i){
    		temp *= nums[i + 1];
    		result[i] *= temp;
    	}
    	return result;
    }
};

int main(){
	Solution testcase;
	vector<int> testvector;
	cout << "please input the testvector(EOF= -9999) :" << endl;
	int input;
	while (cin >> input && input != -9999){
		testvector.push_back(input);
	}
	vector<int> testresult;
	testresult = testcase.productExceptSelf(testvector);
	cout << "the result is: " << endl;
	for (int i = 0; i < testresult.size(); ++i)
	{
		cout << testresult[i] << '\t';
	}
	cout << endl;
	return 0;
}