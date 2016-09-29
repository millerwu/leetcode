//source: https://leetcode.com/problems/recover-binary-search-tree/

/*
Two elements of a binary search tree (BST) are swapped by mistake.

Recover the tree without changing its structure.

Note:
A solution using O(n) space is pretty straight forward. Could you devise a constant space solution?

*/

#include <iostream>
#include <vector>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void inorderTravel(TreeNode* node, std::vector<TreeNode*>& list, std::vector<int>& list_val)
{
	if (node == NULL)
	{
		return;
	}
	inorderTravel(node->left, list, list_val);
	list.push_back(node);
	list_val.push_back(node->val);
	inorderTravel(node->right, list, list_val);
}
 
void recoverTree(TreeNode* root) {
	vector<TreeNode*> list_node;
	vector<int> list_val;
	inorderTravel(root, list_node, list_val);
	sort(list_val.begin(), list_val.end());
	for (int i = 0; i < list_node.size(); ++i)
	{
		list_node[i]->val = list_val[i];
	}
	return;
}

int main ()
{
	return 0;
}
