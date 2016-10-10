//229. Majority Element II
//Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times. The algorithm should run in linear time and in O(1) space.

#include <iostream>
#include <vector>

using namespace  std;

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
    	vector<int> result;
    	int y = 0, z = 1;
    	int cy = 0, cz = 0;
    	for (auto x : nums)
    	{
    		if (x == y) cy++;
    		else if (x == z) cz++;
    		else if (! cy) y = x, cy = 1;
    		else if (! cz) z = x, cz = 1;
    		else cy --, cz --;
    	}
    	cy = 0;
    	cz = 0;
    	for (auto x : nums){
    		if (x == y) cy++;
    		if (x == z) cz++;
    	}
    	if (cy > nums.size() / 3) result.push_back(y);
    	if (cz > nums.size() / 3) result.push_back(z);
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
	testresult = testcase.majorityElement(testvector);
	cout << "the result is: " << endl;
	for (int i = 0; i < testresult.size(); ++i)
	{
		cout << testresult[i] << endl;
	}
	return 0;
}


