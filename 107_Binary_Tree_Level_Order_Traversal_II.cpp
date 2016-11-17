//107. Binary Tree Level Order Traversal II
// /Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).
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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> result;
        if(!root) return result;
        vector<TreeNode*> pre = {root};
        vector<TreeNode*> cur;
        while(pre.size()){
        	vector<int> temp;
        	for (auto i : pre){
        		if (i == NULL) continue;
        		cur.push_back(i -> left);
        		cur.push_back(i -> right);
        		temp.push_back(i -> val);
        	}
        	if (temp.size()) result.push_back(temp);
        	swap(cur, pre);
        	cur.clear();
        }
        reverse(result.begin(), result.end());
        return result;
    }
};




