//2. Add Two Numbers
//You are given two linked lists representing two non-negative numbers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    	int carry = 0, sum = 0, remainder;
    	ListNode* result, * temp = new ListNode(0);
    	head = temp;
    	while (l1 != NULL || l2 != NULL || carry != 0){
    		sum = (l1 == NULL? 0 : l1 -> val) + (l2 == NULL? 0 : l2 -> val) + carry;
    		remainder = sum % 10;
    		carry = sum / 10;
    		ListNode* node = new ListNode(remainder);
    		temp -> next = node;
    		temp = temp -> next;
    		l1 = (l1 == NULL? NULL : l1 -> next);
    		l2 = (l2 == NULL? NULL : l2 -> next);
    	}
    	return head -> next;
    }
};