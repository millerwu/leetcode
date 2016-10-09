//source: https://leetcode.com/problems/minimum-depth-of-binary-tree/

/*
Given a binary tree, find its minimum depth.

The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.
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

int minDepth(TreeNode* root) {
    if (root == NULL)
    {
    	return 0;
    }
    int left_min = minDepth(root->left);
    int right_min = minDepth(root->right);
    if (left_min == 0 && right_min == 0)
    {
    	return 1;
    }
    if (left_min == 0)
    {
    	left_min = INT_MAX;
   	}
   	if (right_min == 0)
   	{
   		right_min = INT_MAX;
   	}
    return min(left_min, right_min) + 1;
}

int main ()
{
	return 0;
}
