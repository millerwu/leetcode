//source: https://leetcode.com/problems/remove-duplicates-from-sorted-list/

/*
Given a sorted linked list, delete all duplicates such that each element appear only once.

For example,
Given 1->1->2, return 1->2.
Given 1->1->2->3->3, return 1->2->3.
*/

#include <iostream>

using namespace std;

 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    static ListNode* deleteDuplicates(ListNode* head) {
    	// if ()
    	ListNode* n = new ListNode(0);
    	n->next = head;
    	while (n->next!=NULL && n->next->next!=NULL)
    	{
		if (n->next->val == n->next->next->val)
		{
			n->next ->next = n->next->next->next;
			continue;
		} 
		n = n->next;
    	}
    	return head;
    }
};

void printList(ListNode* node)
{
	while (node!=NULL)
	{
		cout<< node->val << " ";
		node = node->next;
	}
	cout << endl;

}

int main ()
{
	ListNode* l1 = new ListNode(1);
	ListNode* l11 = new ListNode(1);
	ListNode* l111 = new ListNode(1);
	l1->next = l11;
	l11->next = l111;
	// ListNode* l2 = new ListNode(2);
	// l11->next = l2;
	// ListNode* l22 = new ListNode(2);
	// l2->next = l22;
	// ListNode* l3 = new ListNode(3);
	// l22->next = l3;

	printList(l1);
	ListNode* tl = Solution::deleteDuplicates(l1);
	printList(tl);
}
