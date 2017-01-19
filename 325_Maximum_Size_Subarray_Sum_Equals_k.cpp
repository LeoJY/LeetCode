//325. Maximum Size Subarray Sum Equals k
//Given an array nums and a target value k, find the maximum length of a subarray that sums to k. If there isn't one, return 0 instead.
//Note:
//The sum of the entire nums array is guaranteed to fit within the 32-bit signed integer range.
//Follow Up:
//Can you do it in O(n) time?

class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        unordered_map<int, int>myMap;
        int result = 0, temp = 0;
        for (int i = 0; i < nums.size(); i++){
            temp += nums[i];
            if (temp == k) result = i + 1;
            else if (myMap.find(temp - k) != myMap.end()) result = max(result, i - myMap[temp - k]);
            if (myMap.find(temp) == myMap.end()) myMap[temp] = i;
        }
        return result == INT_MIN ? 0 : result;
    }
};