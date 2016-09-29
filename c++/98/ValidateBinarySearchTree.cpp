//source: https://leetcode.com/problems/validate-binary-search-tree/

/*
Given a binary tree, determine if it is a valid binary search tree (BST).

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
Example 1:
    2
   / \
  1   3
Binary tree [2,1,3], return true.
Example 2:
    1
   / \
  2   3
Binary tree [1,2,3], return false.
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

// use stack to store node;
// The solution is the same with inorder Traversal
bool isValidBST(TreeNode* root) {
	if (root == NULL)
	{
		return true;
	}
	vector<TreeNode*> stack;
	TreeNode* node = root;
	int last_val = INT_MIN;
	bool first = true;
	stack.push_back(node);
	while (node != NULL && stack.size() > 0)
	{	
		if (node->left != NULL)
		{
			node = node->left;
			stack.push_back(node);
			continue;
		} else {
			while (stack.size() > 0)
			{
				TreeNode* n = stack.back();
				stack.pop_back();
				if (n->val > last_val || first)
				{
					first = false;
					last_val = n->val;
				} else{
					return false;
				}
				if (n->right != NULL)
				{
					node = n->right;
					stack.push_back(node);
					break;
				}				
			}
		}
	}
	return true;
}

TreeNode* createTree(int a[], int n)
{
    if (n<=0) return NULL;

    TreeNode **tree = new TreeNode*[n];

    for(int i=0; i<n; i++) {
        if (a[i]==0 ){
            tree[i] = NULL;
            continue;
        }
        tree[i] = new TreeNode(a[i]);
    }
    int pos=1;
    for(int i=0; i<n && pos<n; i++) {
        if (tree[i]){
            tree[i]->left = tree[pos++];
            if (pos<n){
                tree[i]->right = tree[pos++];
            }
        }
    }
    return tree[0];
}


int main ()
{
	cout << isValidBST(NULL) << endl;

  int a[]={1,1};
  cout << isValidBST(createTree(a, sizeof(a)/sizeof(int))) << endl;
  
  int b[]={4,2,6,1,7,5,7};
  cout << isValidBST(createTree(b, sizeof(b)/sizeof(int))) << endl;

  int c[]={4,2,6,1,3,5,7};
  cout << isValidBST(createTree(c, sizeof(c)/sizeof(int))) << endl;
  return 0;
}
