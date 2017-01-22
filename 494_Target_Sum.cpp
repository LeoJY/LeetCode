//494. Target Sum
//You are given a list of non-negative integers, a1, a2, ..., an, and a target, S. Now you have 2 symbols + and -. For each integer, you should choose one from + and - as its new symbol.
//Find out how many ways to assign symbols to make sum of integers equal to target S.

//Note:
//The length of the given array is positive and will not exceed 20.
//The sum of elements in the given array will not exceed 1000.
//Your output answer is guaranteed to be fitted in a 32-bit integer.


//DFS
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
    	return helper(nums, S, 0, 0);    
    }
private:
	int helper(vector<int>& nums, int S, int index, int sum){
		if (index == nums.size()){
			if (sum == S) return 1;
			else return 0;
		}
		int count = 0;
		count += helper(nums, S, index + 1, smu + nums[index]);
		count += helper(nums, S, index + 1, smu - nums[index]);
		return count;
	}
};

//DP
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
    	int sum = 0;
    	for (int i = 0; i < nums.size(); i++){
    		sum += nums[i];
    		nums[i] *= 2;
    	}
    	if (sum < S) return 0;
    	return dp(nums, S + sum);
	}
private:
	int dp(vector<int>& nums, int target){
		int n = nums.size();
		vector<vector<int>> result(target + 1, vector<int>(n + 1, 0));
		result[0][0] = 1;
		for (int i = 0; i < target + 1; i++){
			for(int j = 1; j < n + 1; j ++){
				result[i][j] = result[i][j - 1];
				if (i >= nums[j - 1]) result[i][j] += result[i - nums[j - 1]][j - 1];
			}
		}
		return result[target][n];
	}
};
