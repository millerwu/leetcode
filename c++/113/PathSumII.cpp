//source: https://leetcode.com/problems/path-sum-ii/

/*
Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.

For example:
Given the below binary tree and sum = 22,
              5
             / \
            4   8
           /   / \
          11  13  4
         /  \    / \
        7    2  5   1
return
[
   [5,4,11,2],
   [5,8,4,5]
]
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

void pathSumHelper(TreeNode* root, int sum, vector<int> output, vector<vector<int> >& res) {
  output.push_back(root->val);
  if ((sum - root->val) == 0)
  {
    if (root->left == NULL && root->right == NULL)
    {
      res.push_back(output);
      return res;
    }
  }
  if (root->left != NULL)
  {
    pathSumHelper(root->left, sum - root->val, output, res);
  }
  if (root->right != NULL)
  {
    pathSumHelper(root->right, sum - root->val, output, res);
  }
  
}

vector<vector<int> > pathSum(TreeNode* root, int sum) {
  vector<vector<int> > res;
  if (root == NULL)
  {
    /* code */
    return res;
  }
  vector<int> output;
  pathSumHelper(root, sum, output, res);
  return res;
}

int main ()
{
	return 0;
}
