#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<cstring>
#include<string>
#include<map>
#include<vector>
#include<algorithm>

using namespace std;

/*leecodeGiven a binary tree, return the inorder traversal of its nodes' values.

Example:
Input: [1,null,2,3]
   1
    \
     2
    /
   3

Output: [1,3,2]

Follow up: Recursive solution is trivial, could you do it iteratively?

*/

 struct TreeNode {
     int val;
    TreeNode *left;
     TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	vector<int> inorderTraversal(TreeNode* root) {

		vector<int> v;
		inorder(root, v);
		return v;
	}

private:
	void inorder(TreeNode *root, vector<int> &v)
	{
		if (root != NULL)
		{
			inorder(root->left, v);
			v.push_back(root->val);
			inorder(root->right, v);
		}
	}

};