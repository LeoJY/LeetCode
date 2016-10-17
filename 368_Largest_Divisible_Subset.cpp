//368. Largest Divisible Subset
//Given a set of distinct positive integers, find the largest subset such that every pair (Si, Sj) of elements in this subset satisfies: Si % Sj = 0 or Sj % Si = 0.
//If there are multiple solutions, return any subset is fine.

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
    	int maxPointer, maxLen = INT_MIN, n = nums.size();
    	vector<int> son(n, 0);
    	vector<int> dpLen(n, 0);
    	vector<int> result = {};
    	sort(nums.begin(), nums.end());
    	for (int i = 0; i < n; ++i)
    	{
    		for (int j = i; j >= 0 ; --j)
    		{
    			if (nums[i] % nums[j] == 0 && dpLen[i] < dpLen[j] + 1)
    			{
    				dpLen[i] = dpLen[j] + 1;
    				son[i] = j;
    			}
    		}
    		maxLen = max(maxLen, dpLen[i]);
    		maxPointer = maxLen == dpLen[i] ? i : maxPointer;
    	}
    	for (int i = 0; i < maxLen; ++i){
    		result.insert(result.begin(), nums[maxPointer]);
    		maxPointer = son[maxPointer];
    	}
    	return result;
    }	
};

int main(){
	Solution testCase;
	vector<int> testVector;
	vector<int> testResult;
	cout << "please input the testVector (EOF == -9999) : " << endl;
	int temp;
	while (cin >> temp && temp != -9999){
		testVector.push_back(temp);
	}
	testResult = testCase.largestDivisibleSubset(testVector);
	for (auto i : testResult)
	{
		cout << i << '\t';
	}
	cout << endl;
	return 0;
}
