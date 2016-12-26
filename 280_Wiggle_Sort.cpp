//280. Wiggle Sort
//Given an unsorted array nums, reorder it in-place such that nums[0] <= nums[1] >= nums[2] <= nums[3]....


class Solution {
public: 
    void wiggleSort(vector<int>& nums) {
        for (int i = 1; i < nums.size(); i ++){
        	if (((i & 1) && nums[i] < nums[i - 1]) || ((!(i & 1) && nums[i] > nums[i - 1]))) swap(nums[i], nums[i - 1]);
        }
    } 
};