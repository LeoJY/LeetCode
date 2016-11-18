//113. Path Sum II
//Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.
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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> result;
        vector<int> temp;
        helper(root, sum, temp, result);
        return result;
    }
private:
	void helper(TreeNode* root, int sum, vector<int>& temp, vector<vector<int>>& result){
		if (root == NULL) return;
		temp.push_back(root -> val);
		if (root -> left == NULL && root -> right == NULL && sum == root -> val){
			result.push_back(temp);
		}
		helper(root -> left, sum - root -> val, temp, result);
		helper(root -> right, sum - root -> val, temp, result);
		temp.pop_back();
	}
};






