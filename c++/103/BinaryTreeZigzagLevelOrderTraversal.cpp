//source: https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/

/*
Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its zigzag level order traversal as:
[
  [3],
  [20,9],
  [15,7]
]
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

vector<vector<int> > zigzagLevelOrder(TreeNode* root) {
  vector<vector<int> > res;
  if (root == NULL)
  {
    return res;
  }
  vector<int> val;
  vector<TreeNode*> parent;
  vector<TreeNode*> stack;
  parent.push_back(root);
  bool forward = true;
  while (parent.size() > 0)
  {
    while (parent.size() > 0)
    {
      TreeNode* node = parent.back();
      val.push_back(node->val);
      parent.pop_back();
      if (forward)
      {
        if (node->left != NULL)
        {
          stack.push_back(node->left);
        }
        if (node->right != NULL)
        {
          stack.push_back(node->right);
        }
      } else {
        if (node->right != NULL)
        {
          stack.push_back(node->right);
        }
        if (node->left != NULL)
        {
          stack.push_back(node->left);
        }
      }
    }
    res.push_back(val);
    val.clear();
    parent = stack;
    stack.clear();
    forward = !forward;
  }
  return res;
}

int main ()
{
	return 0;
}
