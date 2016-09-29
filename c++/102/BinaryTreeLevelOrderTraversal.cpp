//source: https://leetcode.com/problems/binary-tree-level-order-traversal/

/*
Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its level order traversal as:
[
  [3],
  [9,20],
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

vector<vector<int> > levelOrder(TreeNode* root) {
  vector<vector<int> > res;
  if (root == NULL)
  {
    return res;
  }
  vector<TreeNode*> parent;
  vector<TreeNode*> node;
  vector<int> val;
  parent.push_back(root);
  while (parent.size() > 0)
  {
    while (parent.size() > 0)
    {
      TreeNode* r = parent.front();
      val.push_back(r->val);
      parent.erase(parent.begin());
      if (r->left != NULL)
      {
        node.push_back(r->left);
      }
      if (r->right != NULL)
      {
        node.push_back(r->right);
      }
    }
    res.push_back(val);
    val.clear();
    parent = node;
    node.clear();
  }
  return res;     
}

TreeNode* createTree(int a[], int n) {
  if (n <= 0)
    return NULL;
  TreeNode** tree = new TreeNode*[n];
  // cout << "createTree in" << endl;

  for (int i = 0; i < n; ++i)
  {
    if (a[i] == 0)
    {
      tree[i] == NULL;
    } else {
      tree[i] = new TreeNode(a[i]);
    }
  }
  // cout << "createTree mid" << endl;
  int pos = 1;
  for (int i = 0; i<n && pos<n ; ++i)
  {
    if (tree[i] != NULL)
    {
      tree[i]->left = tree[pos++];
      if (pos < n)
      {
        tree[i]->right = tree[pos++];
      }
    }
  }
  // cout << "createTree end" << endl;
  return tree[0];
}

void printTree(TreeNode* node)
{
  if (node == NULL)
  {
    return;
  }
  // cout<< "printTree" << endl;
  printTree(node->left);
  cout<< node->val << " ";
  printTree(node->right);
}

void printVector(vector<vector<int> > v)
{
  for (int i = 0; i < v.size(); ++i)
  {
    for (int j = 0; j < v[i].size() ; ++j)
    {
      cout << v[i][j] << " ";
    }
    cout << endl;
  }
}

int main ()
{
  int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0, 10, 9};
  TreeNode* node = createTree(a, sizeof(a)/sizeof(int));
  printTree(node);
  cout<< "printTree out" << endl;
  vector<vector<int> > res = levelOrder(node);
  printVector(res);
	return 0;
}
