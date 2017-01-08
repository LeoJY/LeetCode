//138. Copy List with Random Pointer
//A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.
//Return a deep copy of the list.


/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
    	if (head == NULL) return NULL;
    	RandomListNode *newHead, *p1, *p2;
    	for (p1 = head; p1 != NULL; p1 = p1 -> next -> next){
    		p2 = new RandomListNode(p1 -> label);
    		p2 -> next = p1 -> next;
    		p1 -> next = p2 ;
    	}
    	newHead = head -> next;
    	for (p1 = head; p1 != NULL; p1 = p1 -> next -> next){
    		if (p1 -> random) p1 -> next -> random = p1 -> random -> next;
    	}
    	for (p1 = head; p1 != NULL; p1 = p1 -> next){
    		p2 = p1 -> next;
    		p1 -> next = p2 -> next;
    		if (p2 -> next) p2 -> next = p2 -> next -> next;
    	}
    	return newHead;
    }
};