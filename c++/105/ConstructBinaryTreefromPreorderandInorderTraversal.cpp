//source: https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/

/*
Given preorder and inorder traversal of a tree, construct the binary tree.
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

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
}

int main ()
{
	return 0;
}
