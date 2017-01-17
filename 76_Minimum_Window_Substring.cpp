//76. Minimum Window Substring
//Given a string S and a string T, find the minimum window in S which will contain all the characters in T in complexity O(n).
//Note:
//If there is no such window in S that covers all characters in T, return the empty string "".
//If there are multiple such windows, you are guaranteed that there will always be only one unique minimum window in S.

class Solution {
public:
    string minWindow(string s, string t) {
    	if (s.empty() || t.empty()) return "";
    	vector<int> myMap(256, 0);
    	for (auto i : t) myMap[i] ++;
    	int left = 0, right = 0, minLen = INT_MAX, startIdx = -1, count = t.size();
    	while (right <= s.size()){
    		if (myMap[s[right]] > 0) count --;
    		myMap[s[right]] --;
    		right ++;
    		while(count == 0){
    			if (right - left < minLen){
    				minLen = right - left;
    				startIdx = left;
    			}
    			if (myMap[s[left]]++ >= 0) count ++;
    			left ++;
    		}
    	}
    	return (minLen == INT_MAX ? "" : s.substr(startIdx, minLen));
    }
};
