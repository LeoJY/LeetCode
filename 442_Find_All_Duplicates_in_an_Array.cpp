//442. Find All Duplicates in an Array
//Given an array of integers, 1 ≤ a[i] ≤ n (n = size of array), some elements appear twice and others appear once.
//Find all the elements that appear twice in this array.
//Could you do it without extra space and in O(n) runtime?


class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
    	vector<int> result;
        int n = nums.size();
        for (int i = 0; i < n; i++){
        	int temp = abs(nums[i]) - 1;
        	if (nums[temp] > 0) nums[temp] = -nums[temp];
        	else result.push_back(temp + 1);
        }
        return result;
    }
};

