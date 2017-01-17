//485. Max Consecutive Ones
//Given a binary array, find the maximum number of consecutive 1s in this array.
//Note:
//The input array will only contain 0 and 1.
//The length of input array is a positive integer and will not exceed 10,000


class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        if (nums.empty()) return 0;
        int maxLen = INT_MIN;
        int temp = 0;
        for (auto i : nums){
        	temp = (i == 0 ? 0 : temp + 1);
        	maxLen = max(maxLen, temp);
        }
        return maxLen;
    }
};
