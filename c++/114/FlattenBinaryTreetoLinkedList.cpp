//source: https://leetcode.com/problems/flatten-binary-tree-to-linked-list/

/*
Given a binary tree, flatten it to a linked list in-place.

For example,
Given

         1
        / \
       2   5
      / \   \
     3   4   6
The flattened tree should look like:
   1
    \
     2
      \
       3
        \
         4
          \
           5
            \
             6
*/

#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void flatten(TreeNode* root) {
  if (root == NULL || (root->left == NULL && root->right == NULL))
  {
    return;
  }
  if (root->left != NULL) {
    TreeNode* node = root->left;
    while (node->right != NULL) {
      node = node->right;
    }
    node->right = root->right;
    root->right = root->left;
    root->left = NULL;
  }
  flatten(root->right);
    
}

int main ()
{
	return 0;
}
