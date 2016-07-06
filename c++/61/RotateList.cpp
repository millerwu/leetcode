//source: https://leetcode.com/problems/rotate-list/

/*

Given a list, rotate the list to the right by k places, where k is non-negative.

For example:
Given 1->2->3->4->5->NULL and k = 2,
return 4->5->1->2->3->NULL.

Subscribe

*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
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
	static	ListNode* rotateRightNext(ListNode* head)
	{
		if (head==NULL || head->next==NULL)
		{
			return head;
		}
		ListNode* n = head;
		while (n->next->next != NULL)
		{
			n = n->next;
		}
		ListNode* nn = n->next;
		n->next = NULL;
		nn->next = head;
		return nn;
	}
   	static ListNode* rotateRight(ListNode* head, int k) {
		ListNode* l = head;
		int length = 0;
		while (l!=NULL)
		{
			l = l->next;
			length++;			
		}
		if (length == 0)
			return head;

		l = head;
		k = k%length;
		while (k>0)
		{
			l = rotateRightNext(l);
			k--;
		}
		return l;
    }
};

void printListValue(ListNode* head)
{
	ListNode* l = head;
	while (l!=NULL)
	{
		cout << l->val << " "; 
		l = l->next;
	}
	cout << endl;
	return;
}

int main ()
{
	int n = 1;
	int	llength = 5;
	ListNode* head = new ListNode(n);
	ListNode* l = head;
	while (n<=5)
	{
		ListNode* ln = new ListNode(++n);
		l->next = ln;
		l = ln;
	}
	l->next = NULL;

	printListValue(head);

	head = Solution::rotateRight(head, 10);

	printListValue(head);

	return 0;
}
