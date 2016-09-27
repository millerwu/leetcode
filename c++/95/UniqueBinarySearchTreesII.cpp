//source: https://leetcode.com/problems/unique-binary-search-trees-ii/

/*
Given an integer n, generate all structurally unique BST's (binary search trees) that store values 1...n.

For example,
Given n = 3, your program should return all 5 unique BST's shown below.

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
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
 
class Solution {
public:
    static vector<TreeNode*> generateTreesHelper(int start, int end)
    {
      std::vector<TreeNode*> res;
      if (start > end)
      {
        TreeNode* node = NULL;
        res.push_back(node);
        return res;
      }
      for (int i = start; i <= end; ++i)
      {
        vector<TreeNode*> leftTreeNode = generateTreesHelper(start, i-1);
        vector<TreeNode*> rightTreeNode = generateTreesHelper(i+1, end);
        for (int m = 0; m < leftTreeNode.size(); ++m)
        {
          for (int n = 0; n < rightTreeNode.size() ; ++n)
          {
            TreeNode* node = new TreeNode(i);
            node->left = leftTreeNode[m];
            node->right = rightTreeNode[n];
            res.push_back(node);
          }
        }
      }
      return res;
    }
    static vector<TreeNode*> generateTrees(int n) {
      std::vector<TreeNode*> res;
      if (n <= 0)
      {
        return res;
      }
      res = generateTreesHelper(1, n);
      return res;
    }
};

void printTree(TreeNode* root)
{
  if (root == NULL)
  {
    cout << "NULL ";
    return; 
  }
  cout << root->val << " ";
  printTree(root->left);
  printTree(root->right);
}


int main (int argc, char** argv)
{
  if (argc < 2)
  {
    cout << "please input count " << endl;
    return 0;
  }
  int count = atoi(argv[1]);
  vector<TreeNode*> res = Solution::generateTrees(count);
  for (int i = 0; i < res.size(); ++i)
  {
    printTree(res[i]);
    cout<< endl;
  }
	return 0;
}
