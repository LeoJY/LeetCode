//216. Combination Sum III
//Find all possible combinations of k numbers that add up to a number n, given that only numbers from 1 to 9 can be used and each combination should be a unique set of numbers.

#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
    	vector<vector<int>> result;
    	vector<int> temp;
	if (k == 0 || n == 0) return result;
    	helper(result, temp, 1, k, n);
    	return result;
    }

public:
	void helper(vector<vector<int>>& result, vector<int>& temp, int index, const int k, const int n){
		if (k == temp.size() && n == 0){
			result.push_back(temp);
			return;
		}
		if (temp.size() < k && index <= n)
		{
			for (int i = index; i <= 9 && i <=n; ++i)
			{
				temp.push_back(i);
				helper(result, temp, i + 1, k, n - i);
				temp.pop_back();
			}
		}
	}
};

int main(){
	Solution testcase;
	int k, n;
	cout << "please input the test target number: " << endl;
	cin >> n;
	cout << "please input the combinations number" << endl;
	cin >> k;
	vector<vector<int>> testresult; 
	testresult = testcase.combinationSum3(k, n);

	for (int i = 0; i < testresult.size(); ++i)
	{
		for (int j = 0; j < k; ++j)
		{
			cout << testresult[i][j] << '\t';
		}
		cout << endl;
	}

	return 0;
}