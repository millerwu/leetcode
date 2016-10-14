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
	if (root == NULL)
	{
		return 0;
	}
	int left_max = maxPathSumHelper(root->left, max);
	int right_max = maxPathSumHelper(root->right, max);
	int node_max = root->val;
	cout << "left_max = " << left_max << "; right_max = " << right_max << "; node_max = " << node_max << endl; 
	if (left_max > 0)
	{
		node_max += left_max;
	}	
	if (right_max > 0)
	{
		node_max += right_max;
	}
	max = std::max(node_max, max);
	cout << "node_max = " << node_max << " max = " << max << endl;
	return root->val+std::max(0, std::max(left_max, right_max));
}

int maxPathSum(TreeNode* root) {
	int max_sum = 0;
	int total_sum = maxPathSumHelper(root, max_sum);
	return max(total_sum, max_sum); 
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
