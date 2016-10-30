//445. Add Two Numbers II
//You are given two linked lists representing two non-negative numbers. The most significant digit comes first and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.
//You may assume the two numbers do not contain any leading zero, except the number 0 itself.
//Follow up:
//What if you cannot modify the input lists? In other words, reversing the lists is not allowed.
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    	stack<int> num1;
    	stack<int> num2;
    	while(l1){
    		num1.push(l1 -> val);
    		l1 = l1 -> next;
    	}
    	while(l2){
    		num2.push(l2 -> val);
    		l2 = l2 -> next;
    	}
    	ListNode* cur = NULL;
    	int carry = 0;
    	while (!num1.empty() || !num2.empty() || carry){
    		int temp = 0;
    		temp += (num1.empty() ? 0 : num1.top());
    		temp += (num2.empty() ? 0 : num2.top());
    		temp += carry;
    		if (!num1.empty()) num1.pop();
    		if (!num2.empty()) num2.pop();
    		int digit = temp % 10;
    		carry = temp / 10;
    		ListNode* newNode = new ListNode(digit);
    		newNode -> next = cur;
    		cur = newNode;
    	}
    	return cur;
    }
};