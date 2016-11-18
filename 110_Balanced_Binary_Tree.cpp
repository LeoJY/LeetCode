//110. Balanced Binary Tree
//Given a binary tree, determine if it is height-balanced.
//For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//O(n^2)
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if (root == NULL) return true;
        int leftDep = maxDep(root -> left);
        int rightDep = maxDep(root -> right);
        return (abs(leftDep - rightDep) <= 1 && isBalanced(root -> left) && isBalanced(root -> right));
    }
private:
	int maxDep(TreeNode* root){
		if (node == NULL) return 0;
		return 1 + max(maxDep(root -> left), maxDep(root -> right));
	}
};

//O(n)
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        return height(root) != -1;
	}
private:
	int height(TreeNode* root){
		if (root == NULL) return 0;
		int leftHeight = height(root -> left);
		int rightHeight = height(root -> right);
		if (leftHeight == -1 || rightHeight == -1) return -1;
		if (abs(leftHeight - rightHeight) > 1) return -1;
		return max(leftHeight, rightHeight) + 1;
	}
};
