//109. Convert Sorted List to Binary Search Tree
//Given a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    TreeNode* sortedListToBST(ListNode* head) {
    	return helper(head, NULL);
    }
private:
	TreeNode* helper(ListNode* head, ListNode* tail){
		if (head == tail) return NULL;
		if (head -> next == tail){
			TreeNode* root = new TreeNode(head -> val);
			return root;
		}
		ListNode* mid = findMid(head, tail);
		TreeNode* root = new TreeNode(mid -> val);
		root -> left = helper(head, mid);
		root -> right = helper(mid -> next, tail);
		return root;
	}
	ListNode* findMid(ListNode* head, ListNode * tail){
		ListNode*  fast = head, *slow = head;
		while ((fast != tail) && (fast -> next != tail)){
			fast = fast -> next -> next;
			slow = slow -> next;
		}	
		return slow;
	}
};