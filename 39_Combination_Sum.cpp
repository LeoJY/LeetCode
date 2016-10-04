//39. Combination Sum
//Given a set of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.
//The same repeated number may be chosen from C unlimited number of times.

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    	sort(candidates.begin(), candidates.end());
    	vector<vector<int>> result;
    	vector<int> temp;
    	combine(candidates, 0, target, temp, result);
    	return result;
    }

private:
	void combine(const vector<int>& cand, int index, int target, vector<int>& temp, vector<vector<int>>& result){
		for (; index < cand.size() && cand[index] <= target; ++index)
		{
			temp.push_back(cand[index]);
			if (cand[index] == target){
				result.push_back(temp);
			}
			else combine(cand, index, target - cand[index], temp, result);
			temp.pop_back();
		}
	}
};


int main()
{
	Solution testcase;
	//input the target value and array
	cout << "input the test case target value:" << endl;
	int testtarget;
	cin >> testtarget;
	
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

	//call the function
	vector<vector<int>> testresult = testcase.combinationSum( testvector, testtarget);

	//show the result
	cout << "the result is: " << endl;
	for(int i = 0; i < testresult.size(); i++)
	{
		for (int j = 0; j < testresult[i].size(); ++j)
		{
			cout << testresult[i][j] << '\t';
		}
		cout << endl;
	}
	return 0;
}