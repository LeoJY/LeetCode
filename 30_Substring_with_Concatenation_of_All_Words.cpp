//30. Substring with Concatenation of All Words
//You are given a string, s, and a list of words, words, that are all of the same length. Find all starting indices of substring(s) in s that is a concatenation of each word in words exactly once and without any intervening characters.



class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> result;
        int n = s.size();
        int cnt = words.size();
        if (n <= 0 || cnt <= 0) return result;
        unordered_map<string, int> myMap;
        for (auto i : words) {
        	myMap[i] ++;
        }
        int wl = words[0].size();
        for (int i = 0; i < wl; i ++){
        	int left = i, count = 0;
        	unordered_map<string, int> test;
        	for (int j = i; j <= n - wl; j += wl){
        		string temp = s.substr(j, wl);
        		if (myMap.find(temp) != myMap.end()){
        			test[temp] ++;
        			if (test[temp] <= myMap[temp]) count ++;
        			else{
        				while(test[temp] > myMap[temp]){
        					string temp1 = s.substr(left, wl);
        					test[temp1] --;
        					if (test[temp1] < myMap[temp1]) count --;
        					left += wl;
        				}
        			}
        			if (count == cnt){
        				result.push_back(left);
        				test[s.substr(left, wl)] --;
        				left += wl;
        				count --;
        			}
        		}
        		else{
        			test.clear();
        			count = 0;
        			left = j + wl;
        		}
        	}
        } 
        return result;
    }
};