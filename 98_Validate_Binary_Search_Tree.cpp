//98. Validate Binary Search Tree
//Given a binary tree, determine if it is a valid binary search tree (BST).
//Assume a BST is defined as follows:
//
//The left subtree of a node contains only nodes with keys less than the node's key.
//The right subtree of a node contains only nodes with keys greater than the node's key.
//Both the left and right subtrees must also be binary search trees.
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
    bool isValidBST(TreeNode* root) {
    	return helper(root, LONG_MIN, LONG_MAX);
    }
private:
	bool helper(TreeNode* node, long minVal, long maxVal){
		if (node == NULL) return true;
		if (node -> val >= maxVal || node -> val <= minVal) return false;
		return helper(node -> left, minVal, node -> val) && helper(node -> right, node -> val, maxVal);
	}
};



