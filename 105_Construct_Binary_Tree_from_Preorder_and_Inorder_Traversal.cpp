//105. Construct Binary Tree from Preorder and Inorder Traversal
//Given preorder and inorder traversal of a tree, construct the binary tree.
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
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
    	return create(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
    }
private:
	TreeNode *create(const vector<int> &preorder, int ps, int pe, const vector<int> &inorder, int is, int ie){
		if ( ps > pe || is > ie) return NULL;
		TreeNode *root = new TreeNode (preorder[ps]);
		int pos;
		for (int i = is; i <= ie; ++i)
		{
			if (inorder[i] == root -> val){
				pos = i;
				break;
			}
		}
		root -> left = create(preorder, ps + 1, ps + pos - is, inorder, is, pos - 1);
		root -> right = create(preorder, ps + pos - is + 1, pe, inorder, pos + 1, ie);
		return root;
	}
};