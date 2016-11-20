//337. House Robber III
//The thief has found himself a new place for his thievery again. There is only one entrance to this area, called the "root." Besides the root, each house has one and only one parent house. After a tour, the smart thief realized that "all houses in this place forms a binary tree". It will automatically contact the police if two directly-linked houses were broken into on the same night.
//Determine the maximum amount of money the thief can rob tonight without alerting the police.

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int rob(TreeNode* root) {
    	int l = 0, r = 0;
        return helper(root, l, r);
    }
private:
	int helper(TreeNode* node, int& l, int& r){
		if (node == NULL) return 0;
		int ll = 0, lr = 0, rl = 0, rr = 0;
		l = helper(node -> left, ll, lr);
		r = helper(node -> right, rl, rr);
		return max(l + r, ll + lr + rl + rr + node -> val);
	}	
};
