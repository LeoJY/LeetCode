//222. Count Complete Tree Nodes
//Given a complete binary tree, count the number of nodes.
//Definition of a complete binary tree from Wikipedia:
//In a complete binary tree every level, except possibly the last, is completely filled, and all nodes in the last level are as far left as possible. It can have between 1 and 2h nodes inclusive at the last level h.
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
    int countNodes(TreeNode* root) {
    	int lh = 0, lr = 0;
    	TreeNode* lNode = root, rNode = root;
    	while (lNode){
    		lNode = lNode -> left;
    		lh ++;
    	}
    	while (rNode){
    		rNode = rNode -> right;
    		rh ++;
    	}
    	if (lh == rh) return pow(2, lh) - 1;
    	else return 1 + countNodes(root -> left) + countNodes(root -> right);
    }
};