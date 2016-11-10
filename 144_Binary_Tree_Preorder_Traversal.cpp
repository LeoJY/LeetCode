//144. Binary Tree Preorder Traversal
//Given a binary tree, return the preorder traversal of its nodes' values.
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
    vector<int> preorderTraversal(TreeNode* root) {
    	vector<int> result;
    	if (root == NULL) return result;
    	while (root){
    		TreeNode* temp = root -> left;
    		if (temp){
    			while (temp -> right != NULL && temp -> right != root) temp = temp -> right;
    			if (temp -> right == root) temp -> right = NULL;
    			else{
    				temp -> right = root;
    				result.push_back(root -> val);
    				root = root -> left;
    				continue;
    			}
    		}
    		else result.push_back(root -> val);
    		root = root -> right;
    	}
    	return result;
    }
};


