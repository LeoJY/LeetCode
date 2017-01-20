//25. Reverse Nodes in k-Group
//Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.
//k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.
//You may not alter the values in the nodes, only nodes itself may be changed.
//Only constant memory is allowed.


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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == NULL || k == 1) return head;
        ListNode* preheader = new ListNode(-1);
        preheader -> next = head;
        int count = 0;
        ListNode* cur = preheader, *prev = preheader, *post = NULL;
        while(cur -> next){
        	count ++;
        	cur = cur -> next;
        }
        while(count >= k){
        	cur = prev -> next;
        	post = cur -> next;
        	for (int i = 1; i < k; i ++){
        		cur -> next = post -> next;
        		post -> next = prev -> next;
        		prev -> next = post;
        		post = cur -> next;
        	}
        	prev = cur;
        	count -=k;
        }
        return preheader -> next;
    }
};