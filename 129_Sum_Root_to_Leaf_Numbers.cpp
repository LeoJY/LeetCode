//129. Sum Root to Leaf Numbers
//Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.
//An example is the root-to-leaf path 1->2->3 which represents the number 123.
//Find the total sum of all root-to-leaf numbers.

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
    int sumNumbers(TreeNode* root) {
        int temp = 0;
        int result = 0;
        helper(root, temp, result);
        return result;
    }
private:
	void helper(TreeNode* node, int& temp, int& result){
		if (node == NULL) return;
		temp = temp * 10 + node -> val;
		if (node -> left == NULL && node -> right == NULL) result += temp;
		helper(node -> left, temp, result);
		helper(node -> right, temp, result);
		temp = temp / 10;
	}
};



