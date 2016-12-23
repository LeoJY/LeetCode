//128. Longest Consecutive Sequence
//Given an unsorted array of integers, find the length of the longest consecutive elements sequence.


class Solution {
public:
    int longestConsecutive(vector<int> &num) {
    	int n = num.size();
    	unordered_map<int, int> m;
    	int result = INT_MIN;
    	for (int i : num){
    		if (m[i]) continue;
    		result = max(result, m[i] = m[i + m[i + 1]] = m[i - m[i - 1]] = m[i + 1] + m[i - 1] + 1);
    	}
    	return result;
    }
};



