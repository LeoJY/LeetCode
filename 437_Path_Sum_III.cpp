//437. Path Sum III
//You are given a binary tree in which each node contains an integer value.
//Find the number of paths that sum to a given value.
//The path does not need to start or end at the root or a leaf, but it must go downwards (traveling only from parent nodes to child nodes).
//The tree has no more than 1,000 nodes and the values are in the range -1,000,000 to 1,000,000.

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//recursive
class Solution {
public:
    int pathSum(TreeNode* root, int sum) {
        if (root == NULL) return 0;
        return helper(root, 0, sum) + pathSum(root -> left, sum) + pathSum(root -> right, sum);
    }
private:
	int helper(TreeNode* node, int preSum, int& sum){
		if (node == NULL) return 0;
		int cur = preSum + node -> val;
		return (cur == sum) + helper(node -> left, cur, sum) + helper(node -> right, cur, sum);
	}
};

//O(n)
class Solution {
public:
    int pathSum(TreeNode* root, int sum) {
        unordered_map<int, int> sumCount;
        return helper(root, sum, sumCount, 0);
    }
private:
	int helper(TreeNode* node, int sum, unordered_map<int, int>& sumCount, int preSum){
		if (node == NULL) return 0;
		int temp = preSum + node -> val;
		int result = (temp == sum) + (sumCount.count(temp - sum) ? sumCount[temp - sum]: 0);
		sumCount[temp] ++;
		result += helper(node -> left, sum, sumCount, temp) + helper(node -> right, sum, sumCount, temp);
		sumCount[temp] --;
		return result;
	}
};



