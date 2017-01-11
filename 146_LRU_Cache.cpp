//146. LRU Cache
//Design and implement a data structure for Least Recently Used (LRU) cache. It should support the following operations: get and set.
//get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
//set(key, value) - Set or insert the value if the key is not already present. When the cache reached its capacity, it should invalidate the least recently used item before inserting a new item.


class LRUCache{
public:
    LRUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        auto it = myMap.find(key);
        if (it == myMap.end()) return -1;
        updateList(it);
        return it -> second.first;
    }
    
    void set(int key, int value) {
        auto it = myMap.find(key);
        if (it != myMap.end()) updateList(it);
        else{
        	if (myList.size() == cap){
        		myMap.erase(myList.back());
        		myList.pop_back();
        	}
        	myList.push_front(key);
        }
        myMap[key] = make_pair(value, myList.begin());
    }
private:
	int cap;
	list<int> myList;
	unordered_map<int, pair<int, list<int>::iterator>> myMap;
	void updateList(unordered_map<int, pair<int, list<int>::iterator>>::iterator it){
		int key = it -> first;
		myList.erase(it -> second.second);
		myList.push_front(key);
		it -> second.second = myList.begin();
	}
};
