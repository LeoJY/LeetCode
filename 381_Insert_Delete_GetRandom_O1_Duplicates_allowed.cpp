//381. Insert Delete GetRandom O(1) - Duplicates allowed
//Design a data structure that supports all following operations in average O(1) time.
//Note: Duplicate elements are allowed.
//insert(val): Inserts an item val to the collection.
//remove(val): Removes an item val from the collection if present.
//getRandom: Returns a random element from current collection of elements. The probability of each element being returned is linearly related to the number of same value the collection contains.


class RandomizedCollection {
public:
    /** Initialize your data structure here. */
    RandomizedCollection() {
        
    }
    
    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        bool result = (myMap.find(val) == myMap.end());
        myMap[val].push_back(myVec.size());
        myVec.push_back(make_pair(val, myMap[val].size() - 1));
        return result;
    }
    
    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
        if (myMap.find(val) == myMap.end()) return false;
        auto last = myVec.back();
        myMap[last.first][last.second] = myMap[val].back();
        myVec[myMap[val].back()] = last;
        myMap[val].pop_back();
        if (myMap[val].empty()) myMap.erase(val);
        myVec.pop_back();
        return true;
    }
    
    /** Get a random element from the collection. */
    int getRandom() {
        return myVec[rand() % myVec.size()].first;
    }
private:
	vector<pair<int, int>> myVec;
	unordered_map<int, vector<int>> myMap;
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection obj = new RandomizedCollection();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */

