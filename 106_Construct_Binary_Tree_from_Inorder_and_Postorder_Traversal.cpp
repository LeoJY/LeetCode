//106. Construct Binary Tree from Inorder and Postorder Traversal
//Given inorder and postorder traversal of a tree, construct the binary tree.
//Note:
//You may assume that duplicates do not exist in the tree.

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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    	return create(postorder, 0, postorder.size() - 1, inorder, 0, inorder.size() - 1);
    }
private:
	TreeNode *create(const vector<int> &postorder, int ps, int pe, const vector<int> &inorder, int is, int ie){
		if ( ps > pe || is > ie) return NULL;
		TreeNode *root = new TreeNode (postorder[pe]);
		int pos;
		for (int i = is; i <= ie; ++i)
		{
			if (inorder[i] == root -> val){
				pos = i;
				break;
			}
		}
		root -> left = create(postorder, ps, ps + pos - is - 1, inorder, is, pos - 1);
		root -> right = create(postorder, ps + pos - is , pe - 1, inorder, pos + 1, ie);
		return root;
	}
};