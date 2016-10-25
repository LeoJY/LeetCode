//19. Remove Nth Node From End of List
//Given a linked list, remove the nth node from the end of list and return its head.
//Note:
//Given n will always be valid.
//Try to do this in one pass.
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
//solution 1
class Solution{
public:
    ListNode* removeNthFromEnd(ListNode* head, int n){
    	ListNode *fast = head, *slow = head;
    	while (n-- > 0 && fast != NULL) fast = fast -> next;
    	if (fast == NULL) return head -> next;
    	while (fast -> next != NULL){
    		fast = fast -> next;
    		slow = slow -> next;
    	}
    	slow -> next = slow -> next -> next;
    	return head;
    }
};

//solution 2
class Solution{
public:
    ListNode* removeNthFromEnd(ListNode* head, int n){
        ListNode** t1 = &head, *t2 = head;
        for(int i = 1; i < n; ++i) t2 = t2->next;
        while(t2->next != NULL){
            t1 = &((*t1)->next);
            t2 = t2->next;
        }
        ListNode *to_be_delete = *t1;
        *t1 = (*t1)->next;
        delete to_be_delete;
        return head;
    }
};
