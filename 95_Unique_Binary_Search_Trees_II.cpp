//95. Unique Binary Search Trees II
//Given an integer n, generate all structurally unique BST's (binary search trees) that store values 1...n.
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution{
private:
	TreeNode* cloneTree(TreeNode* root){
		if (root == NULL) return NULL;
		TreeNode* newRoot = new TreeNode(root -> val);
		newRoot -> left = cloneTree(root -> left);
		newRoot -> right = cloneTree(root -> right);
		return newRoot;
	}
	void addLeft(TreeNode* oldroot, TreeNode * newroot, vector<TreeNode *>& result){
		TreeNode* cloneroot = cloneTree(oldroot);
		newroot -> left = cloneroot;
		result.push_back(newroot);
	}
	void addRight(TreeNode* oldroot, TreeNode* curNode, TreeNode * newroot, vector<TreeNode *>& result){
		TreeNode* cloneroot = cloneTree(oldroot);
		TreeNode* clonecur = cloneroot;
		while(clonecur -> val != curNode -> val) clonecur = clonecur -> right;
		TreeNode* temp = clonecur -> right;
		clonecur -> right = newroot;
		newroot -> left = temp;
		result.push_back(cloneroot);
	}
public:
    vector<TreeNode *> generateTrees(int n) {
    	vector<TreeNode *> result;
    	if (n == 0) return result;
    	vector<TreeNode *> pre(1, NULL);
    	for (int i = 1; i < n + 1; ++i)
    	{
    		for (int j = 0; j < pre.size(); ++j)
    		{
    			TreeNode* oldroot = pre[j];
    			TreeNode* newroot = new TreeNode(i);
    			addLeft(oldroot, newroot, result);
    			TreeNode* cur = oldroot;
    			while(cur != NULL){
					TreeNode* newnode = new TreeNode(i);
					addRight(oldroot, cur, newnode, result);
    				cur = cur -> right;
    			}
    		}
    		swap(result, pre);
    		result.clear();
    	}
    	return pre;
    }
};