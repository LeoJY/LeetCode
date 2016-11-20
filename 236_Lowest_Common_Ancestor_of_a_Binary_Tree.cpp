//236. Lowest Common Ancestor of a Binary Tree
//Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.
//According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes v and w as the lowest node in T that has both v and w as descendants (where we allow a node to be a descendant of itself).”
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// recursive

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    	if (root == NULL || root == p || root == q) return root;
    	TreeNode* leftNode = lowestCommonAncestor(root -> left, p, q);
    	TreeNode* rightNode = lowestCommonAncestor(root -> right, p, q);
    	return !leftNode ? rightNode : (!rightNode ? leftNode : root);
    }
};

// iterative

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == NULL || root == p || root == q) return root;
    	vector<TreeNode*> pathP, pathQ, temp;
    	TreeNode* pre = NULL;
    	temp.push_back(root);
    	while(pathP.empty() || pathQ.empty()){
    		TreeNode* node = temp.back();
    		if (node == p) pathP = temp;
    		if (node == q) pathQ = temp;
    		if (!node -> left && !node -> right || !node -> right && pre == node -> left || node -> right && pre == node -> right){
    			pre = node;
    			temp.pop_back();
    		}
    		else{
    			if (!node -> left || pre == node -> left) temp.push_back(node -> right);
    			else temp.push_back(node -> left);
    		}
    	}
    	int n = min(pathQ.size(), pathP.size());
    	for (int i = 1; i < n; i ++){
    		if (pathQ[i] -> val != pathP[i] -> val) return pathQ[i - 1];
    	}
    	return pathQ[n - 1];
    }
};