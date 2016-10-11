//source: https://leetcode.com/problems/populating-next-right-pointers-in-each-node-ii/

/*
Follow up for problem "Populating Next Right Pointers in Each Node".

What if the given tree could be any binary tree? Would your previous solution still work?

Note:

You may only use constant extra space.
For example,
Given the following binary tree,
         1
       /  \
      2    3
     / \    \
    4   5    7
After calling your function, the tree should look like:
         1 -> NULL
       /  \
      2 -> 3 -> NULL
     / \    \
    4-> 5 -> 7 -> NULL
*/

#include <iostream>
#include <vector>

using namespace std;

struct TreeLinkNode {
 int val;
 TreeLinkNode *left, *right, *next;
 TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

void connect(TreeLinkNode *root) {
    if (root == NULL)
    {
      return;
    }
    TreeLinkNode* p = root->next;
    while (p != NULL) {
      if (p->left != NULL)
      {
        p = p->left;
        break;
      }
      if (p->right != NULL)
      {
        p = p->right;
        break;
      }
      p = p->next;
    }
    if (root->left != NULL;)
    {
      /* code */
    }
}

int main ()
{
	return 0;
}
