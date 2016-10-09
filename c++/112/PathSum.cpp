//source: https://leetcode.com/problems/path-sum/

/*
Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding up all the values along the path equals the given sum.

For example:
Given the below binary tree and sum = 22,
              5
             / \
            4   8
           /   / \
          11  13  4
         /  \      \
        7    2      1
return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.
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

bool hasPathSumHelper(TreeNode* root, int sum){
  cout << "val = " << root->val << " sum = " << sum << endl;
  if (root->left == NULL && root->right == NULL)
  {
    return (sum - root->val) == 0; 
  }
  if (root->left != NULL && root->right != NULL)
  {
    return hasPathSumHelper(root->left, sum - root->val) || hasPathSumHelper(root->right, sum - root->val);
  }
  else if (root->right != NULL)
  {
    return hasPathSumHelper(root->right, sum - root->val);
  } else {
      return hasPathSumHelper(root->left, sum - root->val);
  }

  return true;
}

bool hasPathSum(TreeNode* root, int sum) {
  if (root == NULL)
  {
    return false;
  } 
  if ((sum - root->val) == 0)
  {
    if (root->left == NULL && root->right == NULL)
    {
      return true;
    }
    return false;
  }
  return hasPathSumHelper(root, sum);
}

int main ()
{
	return 0;
}
