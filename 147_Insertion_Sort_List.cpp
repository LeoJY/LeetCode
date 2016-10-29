//147. Insertion Sort List
//Sort a linked list using insertion sort.
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
    ListNode* insertionSortList(ListNode* head) {
    	ListNode* dummy = new ListNode(INT_MIN);
    	dummy -> next = head;
    	ListNode* curNode = head;
    	while(curNode){
    		if (curNode -> next && ((curNode -> next -> val) < (curNode -> val))){
    			ListNode* pre = dummy;
    			while (((pre -> next -> val) < (curNode -> next -> val)) && pre -> next) pre = pre -> next;
    			ListNode * temp = pre -> next;
    			pre -> next = curNode -> next;
    			curNode -> next = curNode -> next -> next;
    			pre -> next -> next = temp;
    		}
    		else curNode = curNode -> next;
    	}

    	ListNode* result = dummy -> next;
    	delete dummy;
    	return result;
    }
};