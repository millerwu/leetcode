//source: https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/

/*
Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.

For example,
Given 1->2->3->3->4->4->5, return 1->2->5.
Given 1->1->1->2->3, return 2->3.


*/

#include <iostream>

using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

 struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };

class Solution {
public:
 	static ListNode* deleteDuplicates(ListNode* head) {
        		ListNode* node = new ListNode(-1);
        		ListNode* tmp = node;
        		node->next = head;
        		int duplicate = 0;
        		ListNode* dh = NULL;
        		while (node->next!=NULL && node->next->next!=NULL)
        		{
        			if (duplicate == 1)
        			{
        				if (node->next->val != node->next->next->val)
        				{
        					dh->next = node->next->next;
        					duplicate = 0;
        					node = dh;
        					continue;
        				}
        			} else {
        				if (node->next->val == node->next->next->val)
	        			{
	        				dh = node;
	        				duplicate = 1;
	        			}
        			}
        			node = node->next;
        		}
        		if (duplicate==1)
        		{
        			dh->next = node->next->next;
        		}
        		return tmp->next;
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
	l1->next = l11;
	ListNode* l2 = new ListNode(2);
	l11->next = l2;
	ListNode* l22 = new ListNode(2);
	l2->next = l22;
	ListNode* l3 = new ListNode(3);
	l22->next = l3;

	printList(l1);
	ListNode* tl = Solution::deleteDuplicates(l1);
	printList(tl);

	return 0;
}
