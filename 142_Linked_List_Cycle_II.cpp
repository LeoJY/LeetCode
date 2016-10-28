//142. Linked List Cycle II
//Given a linked list, return the node where the cycle begins. If there is no cycle, return null.
//Note: Do not modify the linked list.
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
    ListNode *detectCycle(ListNode *head) {
    	ListNode* fast = head, *slow = head;
    	while (fast && fast -> next){
    		fast = fast -> next -> next;
    		slow = slow -> next;
    		if (fast == slow){
    			ListNode* temp = head;
    			while (temp != slow){
    				temp = temp -> next;
    				slow = slow -> next;
    			}
    			return temp;
    		}
    	}
    	return NULL;
    }
};
