//206. Reverse Linked List
//Reverse a singly linked list.
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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
    	if (m == n) return head;
    	ListNode* newNode = new ListNode(0);
    	newNode -> next = head;
    	ListNode* pstart = newNode;
    	for (int i = 1; i < m; i++) pstart = pstart -> next;
    	ListNode * cur = pstart -> next;
    	for (int i = 0; i < n - m; i++){
    		ListNode* nextNode = cur -> next;
    		cur -> next = nextNode -> next;
    		nextNode -> next = pstart -> next;
    		pstart -> next = nextNode; 
    	}
    	return newNode -> next;
    }
};