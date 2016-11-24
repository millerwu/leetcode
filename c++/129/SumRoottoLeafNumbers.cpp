//source: https://leetcode.com/problems/sum-root-to-leaf-numbers/

/*
Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.

An example is the root-to-leaf path 1->2->3 which represents the number 123.

Find the total sum of all root-to-leaf numbers.

For example,

    1
   / \
  2   3
The root-to-leaf path 1->2 represents the number 12.
The root-to-leaf path 1->3 represents the number 13.

Return the sum = 12 + 13 = 25.


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

void sumNumbersHelper(TreeNode* root, int& sum, int tempsums) {
	if (root->left == NULL && root->right == NULL) {
		sum += tempsums*10 + root->val;
	}
	if (root->left != NULL) {
		sumNumbersHelper(root->left, sum, tempsums*10+root->val);
	}
	if (root->right != NULL) {
		sumNumbersHelper(root->right, sum, tempsums*10+root->val);
	}
}

int sumNumbers(TreeNode* root) {
	int sum = 0;
	int temp = 0;
	if (root == NULL) {
		return 0;
	}
	sumNumbersHelper(root, sum, temp);
	return sum;
}

int main ()
{
	return 0;
}
