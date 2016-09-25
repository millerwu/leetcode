//source: https://leetcode.com/problems/binary-tree-inorder-traversal/

/*
Given a binary tree, return the inorder traversal of its nodes' values.

For example:
Given binary tree [1,null,2,3],
   1
    \
     2
    /
   3
return [1,3,2].
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
		static void inorderTraversalHelper(TreeNode* root, std::vector<int>& res)
		{
			if (root == NULL)
			{
				return;
			}
			inorderTraversalHelper(root->left, res);
			res.push_back(root->val);
			inorderTraversalHelper(root->right, res);
		}
		// use Recursive to resolve this problem
		static std::vector<int> inorderTraversal_Recursive(TreeNode* root)
		{
			std::vector<int> res;
			if (root == NULL)
			{
				return res;
			}
			inorderTraversalHelper(root, res);
			return res;
		}
    static vector<int> inorderTraversal(TreeNode* root) {
    	std::vector<int> res_;
    	std::vector<TreeNode*> stack_;
    	if (root == NULL)
    	{
    		return res_;
    	}
      TreeNode* node_ = root;
      stack_.push_back(node_);
      while (node_ != NULL)
      {
      	// cout << " val = " << node_->val << endl;
      	if (node_->left != NULL)
      	{
      		stack_.push_back(node_->left);
      		node_ = node_->left;
      		continue;
      	}
      	while (stack_.size() > 0)
      	{
      		cout << "stack_ size = " << stack_.size() << endl;
      		node_ = stack_.back();
      		stack_.pop_back();
      		res_.push_back(node_->val);
      		node_ = node_->right;
      		if (node_ != NULL)
      		{
      			stack_.push_back(node_);
      			break;
      		}
      	}
      }
      return res_;
    }
};

void printVectorInt(std::vector<int> v)
{
	for (int i = 0; i < v.size(); ++i)
	{
			cout << v[i] << " ";
	}
	cout << endl;
}

int main ()
{
	TreeNode t1(1);
	TreeNode t2(2);
	TreeNode t3(3);
	t1.right = &t2;
	t2.left = &t3;
	std::vector<int> res = Solution::inorderTraversal_Recursive(&t1);
	printVectorInt(res);
	return 0;
}
