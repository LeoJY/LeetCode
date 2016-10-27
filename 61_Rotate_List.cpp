//61. Rotate List
//Given a list, rotate the list to the right by k places, where k is non-negative.
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
    ListNode* rotateRight(ListNode* head, int k) {
    	if (head == NULL || head -> next == NULL || k == 0) return head;
    	int length = 1;
    	ListNode* temp = head;
    	while( temp -> next != NULL){
    		temp = temp -> next;
    		length ++; 
    	}
    	k %= length;
    	temp -> next = head;
    	temp = head;
    	for (int i = 1; i < length - k; ++i) temp = temp -> next;
    	head = temp -> next;
    	temp -> next = NULL;
    	return head;
    }
};

