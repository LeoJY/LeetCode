//314. Binary Tree Vertical Order Traversal
//Given a binary tree, return the vertical order traversal of its nodes' values. (ie, from top to bottom, column by column).
//If two nodes are in the same row and column, the order should be from left to right.

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
    vector<vector<int>> verticalOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (root == NULL) return result;
        map<int, vector<int>> myMap;
        queue<pair<TreeNode*, int>> myQueue;
        myQueue.push(make_pair(root, 0));
        while(!myQueue.empty()){
        	auto temp = myQueue.front();
        	myQueue.pop();
        	myMap[temp.second].push_back(temp.first -> val);
        	if (temp.first -> left) myQueue.push(make_pair(temp.first -> left, temp.second - 1));
        	if (temp.first -> right) myQueue.push(make_pair(temp.first -> right, temp.second + 1));
        }
        for (auto i : myMap){
        	result.push_back(i.second);
        }
        return result;
    }
};
