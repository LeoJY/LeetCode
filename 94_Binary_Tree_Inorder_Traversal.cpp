//94. Binary Tree Inorder Traversal
//Given a binary tree, return the inorder traversal of its nodes' values.
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
  vector<int> inorderTraversal(TreeNode* p) {
  	vector<int> result;
  	while (p){
  		TreeNode* precessor = p -> left;
  		if (precessor){
  			while (precessor -> right && precessor -> right != p ) precessor = precessor -> right;
  			if (precessor -> right = p) precessor -> right = NULL;
  			else{
  				precessor -> right = p;
  				p = p -> left;
  				//continue;
  			}
  		}
  		result.push_back(p -> val);
  		p = p -> right;
  	}
  	return result;
  }
}；
