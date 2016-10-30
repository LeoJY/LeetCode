//160. Intersection of Two Linked Lists
//Write a program to find the node at which the intersection of two singly linked lists begins.
//Notes:
//If the two linked lists have no intersection at all, return null.
//The linked lists must retain their original structure after the function returns.
//You may assume there are no cycles anywhere in the entire linked structure.
//Your code should preferably run in O(n) time and use only O(1) memory.
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB){
        if (headA == NULL || headB == NULL) return NULL;
    	ListNode* temp = headA;
    	while(temp -> next){
    		temp = temp -> next;
    	}
    	temp -> next = headA;
    	ListNode* fast = headB, *slow = headB;
    	while (fast && fast -> next){
    		fast = fast -> next -> next;
    		slow = slow -> next;
    		if (fast == slow){
    			fast = headB;
    			while (fast != slow){
    				fast = fast -> next;
    				slow = slow -> next;
    			}
    			temp -> next = NULL;
    			return slow;
    		}
    	}
    	temp -> next = NULL;
    	return NULL;
    }
};


