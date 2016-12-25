//259. 3Sum Smaller
//Given an array of n integers nums and a target, find the number of index triplets i, j, k with 0 <= i < j < k < n that satisfy the condition nums[i] + nums[j] + nums[k] < target.
//Follow up:
//Could you solve it in O(n2) runtime?

class Solution {
public:
    int threeSumSmaller(vector<int>& nums, int target) {
        int n = nums.size();
        if (n < 3) return 0;
        int count = 0;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n - 2; i++){
        	if (nums[i] + nums[i + 1] + nums[i + 2] >= target) break;
        	int j = i + 1, k = n - 1;
        	while (j < k){
        		while (j < k && nums[i] + nums[j] + nums[k] >= target) k--;
        		count += k - j;
        		j ++;
        	}
        }
        return count;
    }
};