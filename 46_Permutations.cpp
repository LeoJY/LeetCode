//46. Permutations
//Given a collection of distinct numbers, return all possible permutations.
#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
    	vector<vector<int>> result;
    	helper(nums, 0, result);
    	return result;
    }
private:
	void helper(vector<int>& nums, int i, vector<vector<int>>& result){
		if (i == nums.size() - 1){
			result.push_back(nums);
			return;
		}
		for(int j = i; j < nums.size(); j ++){
			swap(nums[i], nums[j]);
			helper(nums, i + 1, result);
			swap(nums[i], nums[j]);
		}
	}
};

int main(){
	Solution testCase;
	string testString;
	int temp;
	vector<int> testVector;
	cout << "please input the numbers, seperate with space, end with enter" << endl;
	getline(cin, testString);
	istringstream cinstr(testString);
	while(cinstr >> temp){
		testVector.push_back(temp);
	}
	vector<vector<int>> testResult = testCase.permute(testVector);
	for (auto i : testResult){
		for (auto j : i) cout << j << " ";
		cout <<  endl;
	}
	return 0;
}
