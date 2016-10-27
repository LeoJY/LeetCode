//82. Remove Duplicates from Sorted List II
//Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.

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
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == NULL || head -> next == NULL) return head;
        ListNode ** cur = & head;
        while (*cur){
        	if ((*cur) -> next && (*cur) -> next -> val == (*cur) -> val){
        		ListNode* temp = *cur;
        		while (temp && temp -> val == (*cur) -> val) temp = temp -> next;
        		*cur = temp;
        	}
        	else cur = &((*cur) -> next);
        }
        return head;
    }
};
