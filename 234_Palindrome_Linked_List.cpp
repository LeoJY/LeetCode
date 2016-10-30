//234. Palindrome Linked List
//Given a singly linked list, determine if it is a palindrome.
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
	bool isPalindrome(ListNode* head) {
     	if (head == NULL || head -> next == NULL) return true;
    	ListNode *second = splitList(head);
    	second = reverseList(second);
    	while (second){
    		if (second -> val == head -> val){
    			second = second -> next;
    			head = head -> next;
    		}
    		else return false;
    	}
    	return true;
    }
private:
	ListNode* splitList(ListNode* head){
		ListNode* dummy = new ListNode(INT_MIN);
		dummy -> next = head;
		ListNode* fast = dummy, * slow = dummy;
		while(fast && fast -> next){
			fast = fast -> next -> next;
			slow = slow -> next;
		}
		ListNode* result = slow -> next;
		slow -> next = NULL;
		delete dummy;
		return result;
	}
	ListNode* reverseList(ListNode* head){
		ListNode* pre = NULL;
		while (head){
			ListNode* post =  head -> next;
			head -> next = pre;
			pre = head;
			head = post;
		}
		return pre;
	}
};


