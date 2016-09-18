//source: https://leetcode.com/problems/partition-list/

/*
Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.

You should preserve the original relative order of the nodes in each of the two partitions.

For example,
Given 1->4->3->2->5->2 and x = 3,
return 1->2->2->4->3->5.
*/

#include <iostream>
#include <vector>

using namespace std;

  // Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
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
class Solution {
public:
   	static  ListNode* partition(ListNode* head, int x) {
    	ListNode bhead(0);
    	ListNode lhead(0);
    	ListNode* bNode = &bhead;
    	ListNode* lNode = &lhead;
    	ListNode* n = head;
    	while(n != NULL)
    	{
 		// cout << "value = " << n->val << endl;
    		if (n->val < x)
    		{
    			bNode->next = n;
    			bNode = bNode->next;
    			// cout << "BNode value = " << bNode->val << endl;
    		} else {
    			lNode->next = n;
    			lNode = lNode->next;
    			// cout << "lNode value = " << lNode->val << endl;
    		}
    		n = n->next;
    	}
    	lNode->next = NULL;
    	// printList(bhead.next);
    	// printList(lhead.next);
    	bNode->next = lhead.next;
    	
    	return bhead.next;
    }
};

int main ()
{
	ListNode l1(1);
	ListNode l2(4);
	ListNode l3(3);
	ListNode l4(2);
	ListNode l5(5);
	ListNode l6(2);
	l1.next = &l2;
	l2.next = &l3;
	l3.next = &l4;
	l4.next = &l5;
	l5.next = &l6;

	ListNode* r = Solution::partition(&l1, 3);
	printList(r);
	return 0;
}
