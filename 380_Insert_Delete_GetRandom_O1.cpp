//380. Insert Delete GetRandom O(1)
//Design a data structure that supports all following operations in average O(1) time.
//insert(val): Inserts an item val to the set if not already present.
//remove(val): Removes an item val from the set if present.
//getRandom: Returns a random element from current set of elements. Each element must have the same probability of being returned.


class RandomizedSet {
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
    	if (myMap.find(val) != myMap.end()) return false;
    	myVec.push_back(val);
    	myMap[val] = myVec.size() - 1;
    	return true;        
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
    	if (myMap.find(val) == myMap.end()) return false;
    	int last = myVec.back();
    	myMap[last] = myMap[val];
    	myVec[myMap[val]] = last;
    	myVec.pop_back();
    	myMap.erase(val);
    	return true;        
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        return myVec[rand() % myVec.size()];
    }
private:
	vector<int> myVec;
	unordered_map<int, int> myMap;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */