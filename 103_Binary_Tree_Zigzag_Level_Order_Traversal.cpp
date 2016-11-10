//103. Binary Tree Zigzag Level Order Traversal
//Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).
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
    vector<vector<int> > zigzagLevelOrder(TreeNode* root) {
    	vector<vector<int>> result;
    	if (root == NULL) return result;
    	queue<TreeNode*> nodeQueue;
    	nodeQueue.push(root);
    	bool leftToRight = true;
    	while(!nodeQueue.empty()){
    		int size = nodeQueue.size();
    		vector<int> row(size);
    		for (int i = 0; i < size; i ++){
    			TreeNode* node = nodeQueue.front();
                nodeQueue.pop();
                int index = (leftToRight) ? i : (size - 1 - i);
                row[index] = node->val;
                if (node->left) {
                    nodeQueue.push(node->left);
                }
                if (node->right) {
                    nodeQueue.push(node->right);
                }
            }  
            leftToRight = !leftToRight;
            result.push_back(row);
        }
        return result;
    }
};