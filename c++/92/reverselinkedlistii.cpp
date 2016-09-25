//source: https://leetcode.com/problems/reverse-linked-list-ii/

/*
Reverse a linked list from position m to n. Do it in-place and in one-pass.

For example:
Given 1->2->3->4->5->NULL, m = 2 and n = 4,

return 1->4->3->2->5->NULL.

Note:
Given m, n satisfy the following condition:
1 ≤ m ≤ n ≤ length of list.
*/

#include <iostream>

using namespace std;


// Definition for singly-linked list.
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
 public:
  static ListNode* reverseBetween(ListNode* head, int m, int n) {
  	if (head == NULL || m < 0 || n < 0 || (n-m) <= 0)
  	{
  		return head;
  	}
  	ListNode fake_(0);
  	fake_.next = head;
  	ListNode* begin_ = &fake_;
  	ListNode* end_ = &fake_;

  	int gap_ = n - m;
  	while (gap_ > 0 && end_ != NULL)
  	{
  		end_ = end_->next;
  		gap_--;
  	}
  	while (m > 1 && begin_ != NULL && end_ != NULL)
  	{
  		begin_ = begin_->next;
  		end_ = end_->next;
  		m--;
  	}
  	// cout << "begin_ value = " << begin_->val << endl;
  	// cout << "end_ value " << end_->val << endl;
  	//p is the node at index m, and q is the node at index n;

  	ListNode* p = begin_->next;
  	ListNode* q = end_->next;

  	//start reverse the list between m & n
  	while (p != q)
  	{
  		ListNode* n = p;
  		p = p->next;
  		n->next = q->next;
  		q->next = n;
  	}
  	// link the list
  	begin_->next = q;
  	return fake_.next;
  }
};


void printList(ListNode* h)
{
    while(h!=NULL){
      cout << h->val << " ";
      h = h->next;
    }
    cout << endl;
}

ListNode* createList(int *a, int n)
{
    ListNode *head=NULL, *p=NULL;
    for(int i=0; i<n; i++){
        if (head == NULL){
            head = p = new ListNode(a[i]);
        }else{
            p->next = new ListNode(a[i]);
            p = p->next;
        }
    }
    return head;
}

ListNode* createList(int len) {
  int *a = new int[len];
  for(int i=0; i<len; i++){
    a[i] = i+1;
  }
  ListNode* h =  createList(a, len);
  delete[] a;
  return h;
}

int main ()
{
	int l=5;
  int m=2, n=4;
  ListNode* h = createList(l);
  printList( h );

  printList( Solution::reverseBetween(h , m, n) );
	return 0;
}
