//77. Combinations
//Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
    	vector<vector<int>> result;
    	vector<int> temp;
    	helper(k, 1, n, temp, result);
    	return result;
    }
private:
	void helper(int k, int begin, int max, vector<int>& temp, vector<vector<int>>& result){
		if (temp.size() == k){
			result.push_back(temp);
			return;
		}
		for (int i = begin; i <= max; i++){
			temp.push_back(i);
			helper(k, i + 1, max, temp, result);
			temp.pop_back();
		}
	}
};

int main()
{
	Solution testCase;
	int testN, testK;
	cout << "please input the number range" << endl;
	cin >> testN;
	cout << "please input the number of the outcome" << endl;
	cin >> testK;
	vector<vector<int>> testResult = testCase.combine(testN, testK);
	for (auto i : testResult){
		for (auto j : i){
			cout << j << " ";
		}
		cout << endl;
	}
	return 0;
}