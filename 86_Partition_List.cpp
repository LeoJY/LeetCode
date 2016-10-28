//86. Partition List
//Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.
//You should preserve the original relative order of the nodes in each of the two partitions.
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
    ListNode* partition(ListNode* head, int x) {
		ListNode* l = new ListNode(0), *lstart = l;
		ListNode* r = new ListNode(0), *rstart = r;
		while (head){
			if (head -> val < x){
				l -> next = head;
				l = l -> next;
			}
			else{
				r -> next = head;
				r = r -> next;
			}
			head = head -> next;
		}  
		l -> next = rstart -> next;
		r -> next = NULL;
		return lstart -> next;
    }
};
