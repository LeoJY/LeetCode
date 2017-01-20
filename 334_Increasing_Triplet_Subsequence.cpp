//334. Increasing Triplet Subsequence
//Given an unsorted array return whether an increasing subsequence of length 3 exists or not in the array.
//Formally the function should:
//Return true if there exists i, j, k 
//such that arr[i] < arr[j] < arr[k] given 0 ≤ i < j < k ≤ n-1 else return false.
//Your algorithm should run in O(n) time complexity and O(1) space complexity.

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int candidtate1 = INT_MAX, candidtate2 = INT_MAX;
        for (auto i : nums){
        	if (i <= candidtate1) candidtate1 = i;
        	else if (i <= candidtate2) candidtate2 = i;
        	else return true;
        }
        return false;
    }
};
