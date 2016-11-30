//307. Range Sum Query - Mutable
//Given an integer array nums, find the sum of the elements between indices i and j (i ≤ j), inclusive.
//The update(i, val) function modifies nums by updating the element at index i to val.
//Note:
//The array is only modifiable by the update function.
//You may assume the number of calls to update and sumRange function is distributed evenly.


class NumArray {
public:
    NumArray(vector<int> &nums) {
        data = nums;
        if (nums.empty()) return;
        biT = vector<int>(nums.size() + 1, 0);
        for (int i = 0; i < nums.size(); i++){
        	int k = i + 1;
        	while (k < biT.size()){
        		biT[k] += nums[i];
        		k += (k & ((~k) + 1));
        	}
        }
    }

    void update(int i, int val) {
        int diff = val - data[i];
        data[i] = val;
        int k = i + 1;
        while (k < biT.size()){
    		biT[k] += diff;
    		k += (k & ((~k) + 1));
    	}
    }

    int sumRange(int i, int j) {
    	if (i == 0) return sumFromZero(j);
    	return sumFromZero(j) - sumFromZero(i - 1);
    }

private:
	vector<int> data;
	vector<int> biT;
	int sumFromZero(int k){
		k++;
		int result = 0;
		while (k){
			result += biT[k];
			k = k & (k - 1);
		}
		return result;
	}
};


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.update(1, 10);
// numArray.sumRange(1, 2);