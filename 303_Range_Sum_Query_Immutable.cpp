//303. Range Sum Query - Immutable
//Given an integer array nums, find the sum of the elements between indices i and j (i ≤ j), inclusive.
//Note:
//You may assume that the array does not change.
//There are many calls to sumRange function.


class NumArray {
public:
    NumArray(vector<int> &nums) {
    	accumulator.push_back(0);
    	for (auto i : nums) accumulator.push_back(accumulator.back() + i);	
    }

    int sumRange(int i, int j) {
    	return accumulator[j + 1] - accumulator[i];
    }
private:
	vector<int> accumulator;
};


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.sumRange(1, 2);

