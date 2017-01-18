//477. Total Hamming Distance
//The Hamming distance between two integers is the number of positions at which the corresponding bits are different.
//Now your job is to find the total Hamming distance between all pairs of the given numbers.
//Note:
//Elements of the given array are in the range of 0 to 10^9
//Length of the array will not exceed 10^4.


class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        if (nums.size() < 2) return 0;
        int result = 0;
        vector<int> count (2, 0);
        while (true){
        	int zeroCount = 0;
        	count[0] = 0;
        	count[1] = 0;
        	for (int i = 0; i <  nums.size(); i++){
        		if (nums[i] == 0) zeroCount ++;
        		count[nums[i] & 1] ++;
        		nums[i] >>= 1;
        	}
        	result += count[0] * count[1];
        	if (zeroCount == nums.size()) return result;
        }
        return result;
    }
};
