//257. Binary Tree Paths
//Given a binary tree, return all root-to-leaf paths.

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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
        if (root == NULL) return result;
        vector<TreeNode*> temp;
        helper(root, temp, result);
        return result;
    }
private:
	void helper(TreeNode* node, vector<TreeNode*>& temp, vector<string>& result){
		temp.push_back(node);
		if (node -> left == NULL && node -> right == NULL){
			result.push_back(printPath(temp));
			temp.pop_back();
			return;
		}
		if (node -> left) helper(node -> left, temp, result);
		if (node -> right) helper(node -> right, temp, result);
		temp.pop_back();
	}
	string printPath(vector<TreeNode*>& temp){
		int n = temp.size();
		if (n == 1) return to_string(temp[0] -> val);
		string result = "";
		for (int i = 0; i < n - 1; i++){
			result += to_string(temp[i] -> val) + "->";
		}
		result += to_string(temp[n - 1] -> val);
		return result;
	}
};


