//92. Reverse Linked List II
//Reverse a linked list from position m to n. Do it in-place and in one-pass.
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:   
    ListNode* reverseList(ListNode* head) {
        if (head == NULL || head -> next == NULL) return head;
    	ListNode * pre = NULL;
    	while(head){
    		ListNode * post = head -> next;
    		head -> next = pre;
    		pre = head;
    		head = post;
    	}
    	return pre;
    }
};

