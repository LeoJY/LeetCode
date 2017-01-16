//386. Lexicographical Numbers
//Given an integer n, return 1 - n in lexicographical order.

class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> result;
        int cur = 1;
        for (int i = 0; i < n; i ++){
        	result.push_back(cur);
        	if (cur * 10 <= n) cur *= 10;
        	else if (cur % 10 != 9 && cur + 1 <= n) cur += 1;
        	else{
        		while ((cur / 10) % 10 == 9) cur /= 10;
        		cur = cur / 10 + 1;
        	}
        }
        return result;
    }
};




