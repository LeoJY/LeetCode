//414. Third Maximum Number
//Given a non-empty array of integers, return the third maximum number in this array. If it does not exist, return the maximum number. The time complexity must be in O(n).


class Solution {
public:
    int thirdMax(vector<int>& nums) {
        set<int> mySet;
        for (auto i : nums){
        	mySet.insert(i);
        	if (mySet.size() > 3) mySet.erase(mySet.begin());
        }
        return mySet.size() == 3 ? *mySet.begin() : *mySet.rbegin();
    }
};
