//199. Binary Tree Right Side View
//Given a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.
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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        helper(root, 1, result);
        return result;
    }
private:
	void helper(TreeNode* node, int level, vector<int>& result){
		if (node == NULL) return;
		if (result.size() < level) result.push_back(node -> val);
		helper(node -> right, level + 1, result);
		helper(node -> left, level + 1, result); 
	}
};




