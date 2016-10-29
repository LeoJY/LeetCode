//143. Reorder List
//Given a singly linked list L: L0→L1→…→Ln-1→Ln,
//reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…
//You must do this in-place without altering the nodes' values.
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
    void reorderList(ListNode* head) {
    	if (head == NULL || head -> next == NULL || head -> next -> next == NULL) return;
    	ListNode* mid = findMid(head);
    	ListNode* start = mid -> next;
    	mid -> next = NULL;
    	start = reverseList(start);
    	mergeLists(head, start);
    }

private:
	ListNode* findMid(ListNode* head){
		ListNode* dummy = new ListNode(INT_MIN);
		dummy -> next = head;
		ListNode* fast = dummy, *slow = dummy;
		while(fast != NULL && fast -> next != NULL){
			fast = fast -> next -> next;
			slow = slow -> next;
		}
		delete dummy;
		return slow;
	}
	ListNode* reverseList(ListNode* head){
		if (head == NULL || head -> next == NULL) return head;
		ListNode* pre = NULL;
		while (head != NULL){
			ListNode* nextNode = head -> next;
			head -> next = pre;
			pre = head;
			head = nextNode;
		}
		return pre;
	}
	void mergeLists(ListNode* head1, ListNode* head2){
		while (head1 && head2){
			ListNode* head1Next = head1 -> next,* head2Next = head2 -> next;
			head1 -> next = head2;
			head2 -> next = head1Next;
			head1 = head1Next;
			head2 = head2Next;
		}
	}
};
