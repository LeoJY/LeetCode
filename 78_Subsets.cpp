//78. Subsets
//Given a set of distinct integers, nums, return all possible subsets.
//Note: The solution set must not contain duplicate subsets.

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
    	sort(nums.begin(), nums.end());
    	vector<int> temp;
    	vector<vector<int>> result;
    	helper(nums, temp, result, 0);
    	return result;
    }

private:
	void helper(const vector<int>& nums, vector<int>& temp, vector<vector<int>>& result, int index){
		for (int i = index ; i < nums.size(); ++i)
		{
			temp.push_back(nums[i]);
			helper(nums, temp, result, i + 1);
			temp.pop_back();
		}
		result.push_back(temp);
	}
};


int main(){
	Solution testcase;
	vector<int> testvector;
	int input;

	cout << "input the array (EOF = -9999): " << endl;
	while ( cin >> input && input != -9999){
		testvector.push_back(input);
	}

	vector<vector<int>> testresult;

	testresult = testcase.subsets(testvector);

	for (int i = 0; i < testresult.size(); ++i)
	{
		for (int j = 0; j < testresult[i].size(); ++j)
		{
			cout << testresult[i][j] << '\t';
		}
		cout << endl;
	}
}
