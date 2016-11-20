//404. Sum of Left Leaves
//Find the sum of all left leaves in a given binary tree.

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 //recursive
class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if (root == NULL) return 0;
        int result = 0;
        if (root -> left){
        	if (root -> left -> left == NULL && root -> left -> right == NULL) result += root -> left -> val;
        	else result += sumOfLeftLeaves(root -> left);
        }
        if (root -> right) result += sumOfLeftLeaves(root -> right);
        return result;
    }
};

//iterative
class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if (root == NULL) return 0;
        int result = 0;
        stack<TreeNode*> myStack;
        myStack.push(root);
        while(!myStack.empty()){
        	TreeNode* temp = myStack.top();
        	myStack.pop();
        	if (temp -> left){
        		if (temp -> left -> left == NULL && temp -> left -> right == NULL) result += temp -> left -> val;
        		else myStack.push(temp -> left);
        	}
        	if (temp -> right) myStack.push(temp -> right);
        }
        return result;
    }
};
