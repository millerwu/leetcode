//source: https://leetcode.com/problems/symmetric-tree/

/*
Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

For example, this binary tree [1,2,2,3,4,4,3] is symmetric:

    1
   / \
  2   2
 / \ / \
3  4 4  3
But the following [1,2,2,null,3,null,3] is not:
    1
   / \
  2   2
   \   \
   3    3
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

bool isSymmetricHelper(TreeNode* n1, TreeNode* n2)
{
	if (n1 == NULL && n2 == NULL)
	{
		return true;
	} else if (n1 == NULL || n2 == NULL)
	{
	  return false;
	}
	if (n1->val == n2->val && isSymmetricHelper(n1->left, n2->right) && isSymmetricHelper(n1->right, n2->left))
	{
		return true;
	}
	return false;
}

bool isSymmetric(TreeNode* root) {
	if (root == NULL)
	{
		return true;
	}
	return isSymmetricHelper(root->left, root->right);
}

TreeNode* createTree(int a[], n) {
	if (n <= 0)
		return NULL;
	TreeNode** tree = new TreeNode*[n];

	for (int i = 0; i < n; ++i)
	{
		if (a[i] == 0)
		{
			tree[i] == NULL;
		} else {
			tree[i] = new TreeNode(a[i]);
		}
	}
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
	return tree[0];
}

int main ()
{
	return 0;
}
