//102. Binary Tree Level Order Traversal
//Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//can use queue push all the nodes not NULL
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (root == NULL) return result;
        vector<TreeNode*> cur;
        vector<TreeNode*> prev;
        prev.push_back(root);
        while(!prev.empty()){
        	vector<int> temp;
        	for (auto i : prev){
        		if (i -> left) cur.push_back(i -> left);
        		if (i -> right) cur.push_back(i -> right);
        		temp.push_back(i -> val);
        	}
        	result.push_back(temp);
        	swap(cur, prev);
        	cur.clear();
        }
        return result;
    }
};


