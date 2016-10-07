//90. Subsets II
//Given a collection of integers that might contain duplicates, nums, return all possible subsets.

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    	sort(nums.begin(), nums.end());
    	vector<vector<int>> result;
    	vector<int> temp;
    	helper(nums, 0, result, temp);
    	return result;
    }

private:
	void helper(const vector<int>& nums, int index, vector<vector<int>>& result, vector<int>& temp){
		for (int i = index; i < nums.size(); ++i)
		{
			if (i > index && nums[i] == nums[i - 1]) continue;
			temp.push_back(nums[i]);
			helper(nums, i + 1, result , temp);
			temp.pop_back();
		}
		result.push_back(temp);
	}
};

int main(){
	Solution testcase;
	vector<vector<int>> testresult;
	int input;
	vector<int> testvector;
	cout << "please input the testvector (EOF= -9999):" << endl;
	while (cin >> input && input != -9999){
		testvector.push_back(input);
	}

	testresult = testcase.subsetsWithDup(testvector);

	for (int i = 0; i < testresult.size(); ++i)
	{
		for (int j = 0; j < testresult[i].size(); ++j)
		{
			cout << testresult[i][j] << '\t';
		}
		cout << endl;
	}
	return 0;
}