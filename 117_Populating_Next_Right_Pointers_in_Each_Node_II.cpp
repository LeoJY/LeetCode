//117. Populating Next Right Pointers in Each Node II
//Follow up for problem "Populating Next Right Pointers in Each Node".
//What if the given tree could be any binary tree? Would your previous solution still work?
//Note:
//You may only use constant extra space.


/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
    	if (root == NULL) return;
        TreeLinkNode* cur = root;
        TreeLinkNode* head = NULL;
        TreeLinkNode* pre = NULL;
        while(cur != NULL){
        	while(cur != NULL){
        		if (cur -> left != NULL){
        			if (pre != NULL) pre -> next = cur -> left;
        			else head = cur -> left;
        			pre = cur -> left;
        		}
        		if (cur -> right != NULL){
        			if (pre != NULL) pre -> next = cur -> right;
        			else head = cur -> right;
        			pre = cur -> right;
        		}
        		cur = cur -> next;
        	}
        	cur = head;
        	head = NULL;
        	pre = NULL;
        }
    }
};


