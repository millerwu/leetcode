//source: https://leetcode.com/problems/binary-tree-maximum-path-sum/

/*
Given a binary tree, find the maximum path sum.

For this problem, a path is defined as any sequence of nodes from some starting node to any node in the tree along the parent-child connections. The path does not need to go through the root.

For example:
Given the below binary tree,

       1
      / \
     2   3
Return 6.
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

int maxPathSumHelper(TreeNode* root, int& max) {
	
}

int maxPathSum(TreeNode* root) {
    
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

// int maxPathSum(TreeNode* root) {
    
// }

int main ()
{
	int a[] = {2, 1, 1, 10, 6, 1, 1};
	TreeNode* root = createTree(a, sizeof(a)/sizeof(int));
	int res = maxPathSum(root);
	cout << "res = " << res << endl;	
	return 0;
}
