//24. Swap Nodes in Pairs
//Given a linked list, swap every two adjacent nodes and return its head.
//Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be changed.
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
    ListNode* swapPairs(ListNode* head) {
    	ListNode **temp = &head, *a, *b;
    	while ( (a = *temp) && (b = a -> next)){
    		a -> next = b -> next;
    		b -> next = a;
    		*temp = b;
    		temp = &(a -> next);
    	}
    	return head;
    }
};