//source: https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/

/*
Given a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.
*/

#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* sortedListToBSTHelper(ListNode* head, int size)
{
	if (head == NULL || size <= 0)
	{
		return NULL;
	}
	int mid = (size-1)/2;
	ListNode* node = head;
	while (mid > 0 && node != NULL)
	{
		node = node->next;
		mid--;
	}
	TreeNode* root = new TreeNode(node->val);
	root->left = sortedListToBSTHelper(head, (size-1)/2);
	root->right = sortedListToBSTHelper(node->next, size-(size-1)/2-1);
	return root;
}

//better solution

TreeNode* sortedListToBSTHelper_better(ListNode*& head, int start, int end) {
	if (start > end)
	{
		return NULL;
	}
	int mid = (start + end) / 2;
	TreeNode* left = sortedListToBSTHelper_better(head, start, mid-1);
	TreeNode* root = new TreeNode(head->val);
	root->left = left;
	head = head->next;
	root->right = sortedListToBSTHelper_better(head, mid+1, end);
	return root;
}

TreeNode* sortedListToBST(ListNode* head) {
    if (head == NULL)
    {
    	return NULL;
    }
    int list_length = 0;
    ListNode* node = head;
    while (node != NULL)
    {
    	list_length++;
    	node = node->next;
    }
    // return sortedListToBSTHelper(head, list_length);
    return sortedListToBSTHelper_better(head, 0, list_length-1);

}



int main ()
{
	return 0;
}
