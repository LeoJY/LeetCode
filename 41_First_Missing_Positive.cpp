//41. First Missing Positive
//Given an unsorted integer array, find the first missing positive integer.
//Your algorithm should run in O(n) time and uses constant space.


class Solution {
public: 
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; i++){
        	while(nums[i] > 0 && nums[i] < n && nums[nums[i] - 1] != nums[i]) swap(nums[i], nums[nums[i] - 1]);
        }
        for (int i = 0; i < n; i ++){
        	if (nums[i] != i + 1) return i + 1;
        }
        return n + 1;
    }
};