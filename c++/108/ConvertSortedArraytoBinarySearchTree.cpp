//source: https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/

/*
Given an array where elements are sorted in ascending order, convert it to a height balanced BST.
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

TreeNode* sortedArrayToBSTHelper(vector<int>& nums, int start, int end) {
	if (start > end)
	{
		return NULL;
	}
	int mid = (start + end) / 2;
	TreeNode* node = new TreeNode(nums[mid]);
	node->left = sortedArrayToBSTHelper(nums, start, mid-1);
	node->right = sortedArrayToBSTHelper(nums, mid+1, end);
	return node;
}

TreeNode* sortedArrayToBST(vector<int>& nums) {
	if (nums.size() <= 0)
	{
		return NULL;
	}
	return sortedArrayToBSTHelper(nums, 0, nums.size()-1);
}

void printTree(TreeNode* root) {
	if (root == nullptr)
	{
		return;
	}
	cout << root->val << " " << endl;
	printTree(root->left);
	printTree(root->right);
}

int main ()
{
	vector<int> nums = {1, 2, 3, 4, 5};
	TreeNode* node = sortedArrayToBST(nums);
	printTree(node);
	return 0;
}
