//421. Maximum XOR of Two Numbers in an Array
//Given a non-empty array of numbers, a0, a1, a2, … , an-1, where 0 ≤ ai < 231.
//Find the maximum result of ai XOR aj, where 0 ≤ i, j < n.
//Could you do this in O(n) runtime?
class TrieNode{
public:
	TrieNode* children[2];
	TrieNode(){
		memset(children, NULL, sizeof(children));
	}
};

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        TrieNode* root = new TrieNode;
        for (auto num : nums){
        	TrieNode* cur = root;
        	for (int i = 31; i >= 0; i --){
        		int curBit = (num >> i) & 1;
        		if (cur -> children[curBit] == NULL) cur -> children[curBit] = new TrieNode;
        		cur = cur -> children[curBit];
        	}
        }
        int maxXor = INT_MIN;
        for (auto num : nums){
        	TrieNode* cur = root;
        	int result = 0;
        	for (int i = 31; i >= 0; i --){
        		int curBit = (num >> i) & 1;
        		if (cur -> children[curBit ^ 1] != NULL) {
        			result += (1 << i);
        			cur = cur -> children[curBit ^ 1];
        		}
        		else cur = cur -> children[curBit];
        	}
        	maxXor = max(maxXor, result);
        }
        return maxXor;
    }
};