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
    if (root == NULL || (root->left == NULL && root->right == NULL))
    {
      return NULL;
    }
    TreeLinkNode* node = NULL;
    TreeLinkNode* root_temp = root;
    while (node == NULL && root_temp != NULL) {
      node = root_temp->left;
      if (node == NULL)
      {
        node = root_temp->right;
        if (node == NULL)
        {
          root_temp = root_temp->next;
        }
      }
    }
    if (root_temp != NULL)
    {
      TreeLinkNode* next_node = NULL;
      if (node == root_temp->left)
      {
        next_node = root_temp->right;
        if (next_node == NULL)
        {
          root_temp = root_temp->next;
        }
      } else {
        root_temp = root_temp->next;
      }
      while (next_node == NULL && root_temp != NULL){
        next_node = root_temp->left;
        if (next_node == NULL)
        {
          next_node = root_temp->right;
          if (next_node == NULL)
          {
            root_temp = root_temp->next;
          }
        }
      }
      node->next = next_node;
      if (node == root_temp->left && next_node == root_temp->right)
      {
        /* code */
        
      }
    } else {
      node->next = NULL;
    }
    connect(root->left);
    connect(root->right);
}

int main ()
{
	return 0;
}
