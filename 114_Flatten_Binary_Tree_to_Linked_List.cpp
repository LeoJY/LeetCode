//114. Flatten Binary Tree to Linked List
//Given a binary tree, flatten it to a linked list in-place.
//Hints:
//If you notice carefully in the flattened tree, each node's right child points to the next node of a pre-order traversal.
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
private:
	TreeNode* pre = NULL;
public:
    void flatten(TreeNode* root) {
        if (root == NULL) return;
        flatten(root -> right);
        flatten(root -> left);
        root -> right = pre;
        root -> left = NULL;
        pre = root;
    }
};



