//23. Merge k Sorted Lists
//Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// solution 1 devide and conquer
class Solution {
private:
    ListNode *mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 ==NULL) return l2;
        else if (l2 == NULL) return l1;
        if (l1 -> val <= l2 -> val){
        	l1 -> next = mergeTwoLists(l1 -> next, l2);
        	return l1;
        }
        else{
        	l2 -> next = mergeTwoLists(l2 -> next, l1);
        	return l2;
        } 	
    }
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
    	int n = lists.size();
    	if (n == 0) return NULL;
    	while (n > 1){
    		for (int i = 0; i < n / 2; ++i){
    	    	lists[i] = mergeTwoLists(lists[i], lists[n - 1 -i]);
    	    }
    	    n = (n + 1) / 2;
    	}
    	return lists[0];
    }
};

//solution 2  priority queue

class Solution {
struct compare{
	bool operator()(ListNode* l1, ListNode* l2){
		return l1 -> val >= l2 -> val;
	}
};

public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
    	priority_queue<ListNode*, vector<ListNode*>, compare> q;
    	for (auto i : lists){
    		if (i) q.push(i);
    	}
    	if (q.empty()) return NULL;
    	ListNode *result = q.top(), *curPointer = result;
    	q.pop();
    	if (result -> next) q.push(result -> next);
    	while (!q.empty()){
    		curPointer -> next = q.top();
    		q.pop();
    		curPointer = curPointer -> next;
    		if (curPointer -> next) q.push(curPointer -> next);
    	}
    	return result;
    }
};