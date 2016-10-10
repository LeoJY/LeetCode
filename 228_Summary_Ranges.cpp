//228. Summary Ranges
//Given a sorted integer array without duplicates, return the summary of its ranges.

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
    	int n = nums.size();
    	vector<string> result;
    	if (n == 0) return result;
    	int i = 0;
    	while(i < n){
    		int start  = i;
    		while ( nums[i + 1] == nums[i] + 1) i++;
    		if (i == start) result.push_back(to_string(nums[start]));
    		else result.push_back(to_string(nums[start]) + "->" + to_string(nums[i]));
    		i++;
    	}
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
	vector<string> testresult;
	testresult = testcase.summaryRanges(testvector);
	for (int i = 0; i < testresult.size(); ++i)
	{
		cout << testresult[i] << endl;
	}
	return 0;
}

