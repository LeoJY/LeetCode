//203. Remove Linked List Elements
//Remove all elements from a linked list of integers that have value val.
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
    ListNode* removeElements(ListNode* head, int val) {
    	ListNode* dummy = new ListNode(INT_MIN);
    	dummy -> next = head;
    	ListNode* cur = dummy;
    	while(cur -> next){
    		if (cur -> next -> val == val){
    			ListNode* temp = cur -> next;
    			cur -> next = cur -> next -> next;
    			delete temp;
    		}
    		else cur = cur -> next;
    	}
    	ListNode* result = dummy -> next;
    	delete dummy;
    	return result;
    }
};


