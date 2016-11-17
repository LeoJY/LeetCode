//99. Recover Binary Search Tree
//Two elements of a binary search tree (BST) are swapped by mistake.
//Recover the tree without changing its structure.
//Note:
//A solution using O(n) space is pretty straight forward. Could you devise a constant space solution?

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
    void recoverTree(TreeNode* root) {
        TreeNode* misplace1 = NULL;
        TreeNode* misplace2 = NULL;
        TreeNode* pre = NULL;
        TreeNode* curNode = root;
        while(curNode){
        	TreeNode* temp = curNode -> left;
        	if(temp){
        		while(temp -> right && temp -> right != curNode) temp = temp -> right;
        		if (temp -> right == curNode) temp -> right = NULL;
        		else {
        			temp -> right = curNode;
        			curNode = curNode -> left;
        			continue;
        		}
        	}
        	if (pre && (pre -> val) > (curNode -> val)){
        		if (misplace1 == NULL){
        			misplace1 = pre;
        			misplace2 = curNode;
        		}
        		else misplace2 = curNode;
        	}
        	pre = curNode;
        	curNode = curNode -> right;
        }
        int temp = misplace1 -> val;
        misplace1 -> val = misplace2 -> val;
        misplace2 -> val = temp;
    }
};


