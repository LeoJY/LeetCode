//111. Minimum Depth of Binary Tree
//Given a binary tree, find its minimum depth.
//The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.
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
    int minDepth(TreeNode* root) {
    	if (root == NULL) return 0;
    	int leftDep = minDepth(root -> left);
    	int rightDep = minDepth(root -> right);
    	return (leftDep == 0|| rightDep == 0) ? (leftDep + rightDep + 1) : (min(leftDep, rightDep) + 1);
    }
};

