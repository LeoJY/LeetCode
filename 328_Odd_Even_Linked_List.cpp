//328. Odd Even Linked List
//Given a singly linked list, group all odd nodes together followed by the even nodes. Please note here we are talking about the node number and not the value in the nodes.
//You should try to do it in place. The program should run in O(1) space complexity and O(nodes) time complexity.
//Note:
//The relative order inside both the even and odd groups should remain as it was in the input. 
//The first node is considered odd, the second node even and so on ...
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
    ListNode* oddEvenList(ListNode* head) {
    	if (head == NULL || head -> next == NULL || head -> next -> next == NULL) return head;
    	ListNode* even = head -> next;
    	head -> next = head -> next -> next;
    	even -> next = NULL;
    	ListNode* curOdd = head, * curEven = even;
    	while(curOdd -> next && curOdd -> next -> next){
    		curEven -> next = curOdd -> next -> next;
    		curOdd -> next -> next = curEven -> next -> next;
    		curEven -> next -> next = NULL;
    		curEven = curEven -> next;
    		curOdd = curOdd -> next;
    	}
    	if (curOdd -> next) curOdd = curOdd -> next;
    	curOdd -> next = even;
    	return head;
    }
};


