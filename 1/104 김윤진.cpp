#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>
#include<string>
#include<map>
#include<vector>

/*leecode 104. Maximum Depth of Binary Tree
Given a binary tree, find its maximum depth.

The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

Note: A leaf is a node with no children.

Example:

Given binary tree [3,9,20,null,null,15,7],
return its depth = 3.
*/
/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/

class Solution {
public:
	int maxDepth(TreeNode* root) {

		if (root != NULL)
			return max((maxDepth(root->left)), (maxDepth(root->right))) + 1;
		else
			return 0;
	}
};
