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

void pathSumHelper(TreeNode* root, int sum, vector<TreeNode*>& stack, vector<int>& output, vector<vector<int> >& res) {
  
}

 vector<vector<int>> pathSum(TreeNode* root, int sum) {
     
 }

int main ()
{
	return 0;
}
