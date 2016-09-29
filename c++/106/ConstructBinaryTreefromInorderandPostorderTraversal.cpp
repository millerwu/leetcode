//source: https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/

/*
Given inorder and postorder traversal of a tree, construct the binary tree.
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

TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        
}

int main ()
{
	return 0;
}
