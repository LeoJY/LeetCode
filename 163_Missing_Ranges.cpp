//163. Missing Ranges
//Given a sorted integer array where the range of elements are in the inclusive range [lower, upper], return its missing ranges.



class Solution {
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        int n = nums.size();
        vector<string> result;
        for (int i = 0; i < n; i++){
        	if (nums[i] == lower) lower ++;
        	else if (nums[i] == upper) upper --;
        	else if (nums[i] < lower || nums[i] > upper) continue;
        	else if (nums[i] == lower + 1) {
        	    result.push_back(to_string(lower));
        	    lower = nums[i] + 1;
        	}
        	else{
        		result.push_back(to_string(lower) + "->" + to_string(nums[i] - 1));
        		lower = nums[i] + 1;
        	}
        }
        if (lower == upper) result.push_back(to_string(lower));
        else if (lower < upper) result.push_back(to_string(lower) + "->" + to_string(upper));
        return result;
    }
};
