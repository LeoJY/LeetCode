//398. Random Pick Index
//Given an array of integers with possible duplicates, randomly output the index of a given target number. You can assume that the given target number must exist in the array.
//Note:
//The array size can be very large. Solution that uses too much extra space will not pass the judge.

class Solution {
private:
    vector<int> candidates;
public:
    Solution(vector<int> nums) {
        candidates = nums;
    }
    
    int pick(int target) {
        int count = 0, result = -1;
        for (int i = 0; i < candidates.size(); i++){
            if (candidates[i] != target) continue;
            else{
                count ++;
                if (count == 0) result = i;
                else if (rand() % count == 0) result = i;
            }
        }
        return result;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * int param_1 = obj.pick(target);
 */
