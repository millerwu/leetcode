//source: https://leetcode.com/problems/maximum-depth-of-binary-tree/

/*
Given a binary tree, find its maximum depth.

The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.
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

void maxDepthHelper(TreeNode* root, int depth, int& res)
{
	if (root == NULL)
	{
		return;
	}
	depth++;
	res = res > depth ? res : depth;
	maxDepthHelper(root->left, depth, res);
	maxDepthHelper(root->right, depth, res);
	return;
}

int maxDepth(TreeNode* root) {
	int res = 0;
	maxDepthHelper(root, 0, res);
	return res;
}

int main ()
{
	return 0;
}
