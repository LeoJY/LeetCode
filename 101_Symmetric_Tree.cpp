//101. Symmetric Tree
//Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).
//Note:
//Bonus points if you could solve it both recursively and iteratively.
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
    bool isSymmetric(TreeNode* root) {
        if (!root) return true;
        return helper(root -> left, root -> right);
    }
private:
	bool helper(TreeNode* leftNode, TreeNode* rightNode){
		if (leftNode == NULL && rightNode == NULL) return true;
		else if (leftNode == NULL || rightNode == NULL) return false;
		else if (leftNode -> val == rightNode -> val) return helper(leftNode -> left, rightNode -> right) && helper(leftNode -> right, rightNode -> left);
		return false;
	}
};

//iterative
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (!root) return true;
        queue<pair<TreeNode*, TreeNode*>>myQueue;
        myQueue.push(make_pair(root -> left, root -> right));
        while(myQueue.size()){
        	auto temp = myQueue.front();
        	myQueue.pop();
        	if (temp.first == NULL && temp.second == NULL) continue;
        	else if (temp.first == NULL || temp.second == NULL) return false;
        	else if (temp.first -> val == temp.second -> val){
        		myQueue.push(make_pair(temp.first -> left, temp.second -> right));
        		myQueue.push(make_pair(temp.first -> right, temp.second -> left));
        	}
        	else return false;
        }
        return true;
    }
};