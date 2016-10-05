//source: https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/

/*
Given inorder and postorder traversal of a tree, construct the binary tree.
*/

#include <iostream>
#include <vector>
#include <map>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* buildTreeHelper(vector<int>& inorder, int in_start, int in_size, 
							vector<int>& postorder, int post_start, int post_size,
								map<int, int>& map) {
	if (post_size < 1)
	{
		return NULL;
	}
	TreeNode* root = new TreeNode(postorder[post_start+post_size-1]);
	int root_index = map.find(root->val)->second;
	int left_size = root_index - in_start;
	int right_size = in_size - (left_size) - 1;
	root->left = buildTreeHelper(inorder, in_start, left_size, postorder, post_start, left_size, map);
	root->right = buildTreeHelper(inorder, root_index+1, right_size, postorder, post_start+left_size, right_size, map);
	return root; 
}

TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
	map<int, int> index_map;
	for (int i = 0; i < inorder.size(); ++i)
	{
		index_map.insert(pair<int, int>(inorder[i], i));
	}
	return buildTreeHelper(inorder, 0, inorder.size(), postorder, 0, postorder.size(), index_map);
}

int main ()
{
	return 0;
}

