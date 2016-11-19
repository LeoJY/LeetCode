//226. Invert Binary Tree
//Invert a binary tree.

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//recursive:
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
    	if (root == NULL) return root;
    	root -> left = invertTree(root -> left);
    	root -> right = invertTree(root -> right);
    	swap(root -> left, root -> right);
    	return root;
    }
};

//iterative

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
    	stack<TreeNode*> myStack;
    	myStack.push(root);
    	while(!myStack.empty()){
    		TreeNode* temp = myStack.top();
    		myStack.pop();
    		if (temp){
    			swap(temp -> left, temp -> right);
    			myStack.push(temp -> left);
    			myStack.push(temp -> right);
    		}
    	}
    	return root;
    }
};