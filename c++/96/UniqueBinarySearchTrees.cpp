//source: https://leetcode.com/problems/unique-binary-search-trees/

/*
Given n, how many structurally unique BST's (binary search trees) that store values 1...n?

For example,
Given n = 3, there are a total of 5 unique BST's.

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
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

//use recurison will be memory limited 

vector<TreeNode*> generateTreesHelper(int start, int end)
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
// Dynamic Program
// if n = 0, f(n) = 1
//		n > 0, f(n) = for_each(0, n-1) : f(left(n))*f(right(n));

int numTrees(int n) {
	if (n <= 0)
	{
		return 0;
	}
  // vector<TreeNode*> res = generateTreesHelper(1, n);
  std::vector<int> res(n+1, 0);
  res[0] = 1;
  for (int i = 1; i <= n ; ++i)
   {
   	for (int j = 0; j < i ; ++j)
   	{
   		// cout << " j = " << j << " i = " << i << endl;
   		res[i] += res[j] * res[i-j-1];	
   		// cout << "res["<< i << "] = " << res[i] << endl;
   	}
   }
  return res[n];
}


int main (int argc, char** argv)
{
	if (argc < 2)
  {
    cout << "please input count " << endl;
    return 0;
  }
  int count = atoi(argv[1]);
  int res = numTrees(count);
  cout << " res = " << res << endl;
	return 0;
}
