//source: https://leetcode.com/problems/add-two-numbers/

/*
You are given two linked lists representing two non-negative numbers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
*/

#include <iostream>
#include <vector>

/**
 * Definition for singly-linked list.
 */
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
	int i = 0;
	ListNode* head = new ListNode(0);
	ListNode* node = head;
	int val;
	while (l1 != nullptr && l2 != nullptr) {
		int val = (l1->val + l2->val + i) %10;
		i = (l1->val + l2->val + i) /10;
		node->next = new ListNode(val);
		node = node->next;
		l1 = l1->next;
		l2 = l2->next;
	}
	while (l1 != nullptr) {
		val = (i + l1->val) %10;
		i = (i+l1->val) /10;
		node->next = new ListNode(val);
		node = node->next;
		l1 = l1->next;
	}
	while (l2 != nullptr) {
		val = (i + l2->val) %10;
		i = (i+l2->val) /10;
		node->next = new ListNode(val);
		node = node->next;
		l2 = l2->next;
	}
	if (i != 0) {
		node->next = new ListNode(i);
		node = node->next;
	}
	return head->next;
}

void printList(ListNode* node) {
	while (node != NULL) {
		cout << node->val << " ";
		node = node->next;
	}
	cout << endl;
}
int main ()
{
	ListNode ln11(1), ln12(9), ln13(9);
	ln11.next = &ln12;
	ln12.next = &ln13;
	ListNode ln21(5), ln22(6), ln23(4);
	ln21.next = &ln22;
	ln22.next = &ln23;
	ListNode* n = addTwoNumbers(&ln11, &ln21);
	printList(n);
	return 0;
}
