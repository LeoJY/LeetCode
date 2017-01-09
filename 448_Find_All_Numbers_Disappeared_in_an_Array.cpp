//448. Find All Numbers Disappeared in an Array
//Given an array of integers where 1 ≤ a[i] ≤ n (n = size of array), some elements appear twice and others appear once.
//Find all the elements of [1, n] inclusive that do not appear in this array.
//Could you do it without extra space and in O(n) runtime? You may assume the returned list does not count as extra space.

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> result;
        int n = nums.size();
        for (int i = 0; i < n; i++){
        	int temp = abs(nums[i]) - 1;
        	if (nums[temp] > 0) nums[temp] = - nums[temp];
        }
        for (int i = 0; i < n; i++){
        	if (nums[i] > 0) result.push_back(i + 1);
        }
        return result;
    }
};