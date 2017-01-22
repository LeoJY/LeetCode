//410. Split Array Largest Sum
//Given an array which consists of non-negative integers and an integer m, you can split the array into m non-empty continuous subarrays. Write an algorithm to minimize the largest sum among these m subarrays.
//Note:
//If n is the length of array, assume the following constraints are satisfied:
//1 ≤ n ≤ 1000
//1 ≤ m ≤ min(50, n)

class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        int maxNum = INT_MIN, sum = 0
        for (auto i : nums){
        	maxNum = max(maxNum, i);
        	sum += i;
        }
        int low = maxNum, high = sum;
        while(low <= high){
        	int mid = low + (high - low) / 2;
        	if (isValid(mid, nums, m))
        		high = mid - 1;
        	else low = mid + 1;
        }
        return low;
    }
private:
	bool isValid(int mid, vector<int>& nums, int m){
		int count = 1; temp = 0;
		for (int i : nums){
			temp += i;
			if (temp > mid){
				tmeo = i;
				count ++;
				if (count > m) return false;
			}
		}
		return true;
	}
};