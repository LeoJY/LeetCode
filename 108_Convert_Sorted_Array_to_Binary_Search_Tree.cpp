//108. Convert Sorted Array to Binary Search Tree
//Given an array where elements are sorted in ascending order, convert it to a height balanced BST.
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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return helper(nums, 0, nums.size() - 1);
    }
private:
	TreeNode* helper(vector<int>& nums, int low, int high){
		if (low > high) return NULL;
		int mid = low + (high - low) / 2;
		TreeNode* curNode = new TreeNode(nums[mid]);
		curNode -> left = helper(nums, low, mid - 1);
		curNode -> right = helper(nums, mid + 1, high);
		return curNode;
	}
};




