//source: https://leetcode.com/problems/balanced-binary-tree/

/*
Given a binary tree, determine if it is height-balanced.
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

int getTreeDepth(TreeNode* root) {
	if (root == NULL)
	{
		return 0;
	}
	return max(getTreeDepth(root->left), getTreeDepth(root->right)) + 1;

}

bool isBalanced(TreeNode* root) {
    if (root == NULL)
    {
    	return true;
    }
    int left_depth = getTreeDepth(root->left);
    int right_depth = getTreeDepth(root->right);
    if (abs(left_depth - right_depth) > 1)
    {
    	return false;
    }
    return isBalanced(root->left)&&isBalanced(root->right);
}

int main ()
{
	return 0;
}
