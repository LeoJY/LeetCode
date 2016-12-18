//45. Jump Game II
//Given an array of non-negative integers, you are initially positioned at the first index of the array.
//Each element in the array represents your maximum jump length at that position.
//Your goal is to reach the last index in the minimum number of jumps.
//Note:
//You can assume that you can always reach the last index.

class Solution {
public:
    int jump(vector<int>& nums) {
         int n = nums.size();
         int start = 0, end = 0, step = 0;
         while (end < n - 1){
         	int maxend = end;
         	step ++;
         	for (int i = start; i <= end; i++){
         		maxend = max(maxend, nums[i] + i);
         	}
         	start = end + 1;
         	end = maxend;
         }
         return step;
    }
};


