//148. Sort List
//Sort a linked list in O(n log n) time using constant space complexity.
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
	ListNode *sortList(ListNode *head) {
		if(head == NULL || head -> next == NULL) return head;
		int length = 0;
		ListNode* cur = head;
		while(cur){
			cur = cur -> next;
			length ++;
		}
		ListNode* dummy = new ListNode(INT_MIN);
		dummy -> next = head;
		ListNode* tail, *left, *right;
		for (int step = 1; step < length; step <<= 1)
		{
			cur = dummy -> next;
			tail = dummy;
			while (cur){
				left = cur;
				right = split(left, step);
				cur = split(right, step);
				tail = merge(left, right, tail);
			}
		}
		ListNode* result = dummy -> next;
		delete dummy;
		return result;
	}
private:
	ListNode *split(ListNode *head, int length){
		if (head == NULL) return NULL;
		for (int i = 1; i < length && head; i++) head = head -> next;
		if (!head) return NULL;
		ListNode* second = head -> next;
		head -> next = NULL;
		return second;
	}

	ListNode *merge(ListNode *l1, ListNode *l2, ListNode* head){
		ListNode * cur = head;
		while(l1 && l2){
			if(l1->val > l2->val){
				cur->next = l2;
				cur = l2;
				l2 = l2->next;
			}
			else{
				cur->next = l1;
				cur = l1;
				l1 = l1->next;
			}
		}
		cur->next = (l1 ? l1 : l2);
		while (cur -> next) cur = cur -> next;
		return cur; 
	}
};


