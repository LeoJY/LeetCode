//167. Two Sum II - Input array is sorted
//Given an array of integers that is already sorted in ascending order, find two numbers such that they add up to a specific target number.
//The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.
//You may assume that each input would have exactly one solution.

#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
	vector<int> twoSum(vector<int>& numbers, int target){
		int low = 0, high = numbers.size() - 1;
		while (low < high){
			int sum = numbers[low] + numbers[high];
			if (sum == target) return {low + 1, high + 1};
			else if (sum > target) low ++;
			else high--;
		}
		return {0, 0};
	}
};

int main(){
	Solution testcase;
	int testtarget;
	vector<int> testvector;
	int input;
	cout << "please input the test target" << endl;
	cin >> testtarget;
	cout << "please input the test vector(EOF = -9999): " << endl;
	while(cin >> input && input != -9999){
		testvector.push_back(input);
	}
	vector<int> testresult = testcase.twoSum(testvector, testtarget);
	cout << "the result is: " << endl;
	for (int i = 0; i < testresult.size(); ++i)
	{
		cout << testresult[i] << '\t';
	}
	cout << endl;

	return 0;
}