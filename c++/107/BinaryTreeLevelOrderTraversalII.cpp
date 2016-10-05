//source: https://leetcode.com/problems/binary-tree-level-order-traversal-ii/

/*
Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its bottom-up level order traversal as:
[
  [15,7],
  [9,20],
  [3]
]
*/



#include <iostream>
#include <vector>
#include <algorithm>    // std::reverse

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<vector<int> > levelOrderBottom(TreeNode* root) {
  if (root == NULL)
  {
    return res;
  }
  vector<TreeNode*> parent;
  vector<int> node_res;
  vector<TreeNode*> back_up;
  TreeNode* node;
  parent.push_back(root);
  node_res.push_back(root->val);
  while (parent.size() > 0)
  {
     if(node_res.size() > 0)
        res.push_back(node_res);
    node_res.clear();    
    while (parent.size() > 0)
    {
      node = parent.front();
    //   node_res.clear();
      if (node->left != NULL)
       {
         back_up.push_back(node->left);
         node_res.push_back(node->left->val);
         cout << "left val = " << node->left->val << endl;
       } 
       if (node->right != NULL)
       {
         back_up.push_back(node->right);
         node_res.push_back(node->right->val);
         cout << "right val = " << node->right->val << endl;
       }
       parent.erase(parent.begin());
    }
    parent = back_up;
    back_up.clear();
  }
  if (node_res.size() > 0)
     res.push_back(node_res);
  std::reverse(res.begin(), res.end());
  return res;
    }

int main ()
{
	return 0;
}
