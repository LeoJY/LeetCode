//376. Wiggle Subsequence
//A sequence of numbers is called a wiggle sequence if the differences between successive numbers strictly alternate between positive and negative. The first difference (if one exists) may be either positive or negative. A sequence with fewer than two elements is trivially a wiggle sequence.
//For example, [1,7,4,9,2,5] is a wiggle sequence because the differences (6,-3,5,-7,3) are alternately positive and negative. In contrast, [1,4,7,2,5] and [1,7,4,5,5] are not wiggle sequences, the first because its first two differences are positive and the second because its last difference is zero.
//Given a sequence of integers, return the length of the longest subsequence that is a wiggle sequence. A subsequence is obtained by deleting some number of elements (eventually, also zero) from the original sequence, leaving the remaining elements in their original order.

#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if (nums.empty()) return 0;
        int high = 1, low = 1, n = nums.size();
        for (int i = 1; i < n; i++){
            if (nums[i] > nums[i - 1]) high = low + 1;
            else if (nums[i] < nums[i - 1]) low = high + 1;
        }
        return max(high, low);
    }
};

int main(){
	Solution testCase;
	string testStr;
	cout << "please input the test numbers, seperate with space, end with enter" << endl;
	getline(cin, testStr);
	istringstream cinstr(testStr);
	int temp;
	vector<int> testVector;
	while (cinstr >> temp){
		testVector.push_back(temp);
	}
	int testResult = testCase.wiggleMaxLength(testVector);
	cout << "the result is  " << testResult << endl;
	return 0;
}