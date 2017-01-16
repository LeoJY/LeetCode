//387. First Unique Character in a String
//Given a string, find the first non-repeating character in it and return it's index. If it doesn't exist, return -1.


class Solution {
public:
    int firstUniqChar(string s) {
        int result = INT_MAX;
        unordered_map<char, pair<int, int>> myMap;
        for (int i = 0; i < s.size(); i ++){
        	myMap[s[i]].first ++;
        	myMap[s[i]].second = i;
        }
        for (auto i : myMap){
        	if (i.second.first == 1) result = min (result, i.second.second);
        }
        return result == INT_MAX ? -1 : result;
    }
};
