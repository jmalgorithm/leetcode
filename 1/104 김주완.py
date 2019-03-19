# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def maxDepth2(self, root: TreeNode, height) -> int:
        if root == None:
            return height
        else:
            h_right = self.maxDepth2(root.right, height + 1)
            h_left = self.maxDepth2(root.left, height + 1)
            return max(h_right, h_left)
        
    def maxDepth(self, root: TreeNode) -> int:
        return self.maxDepth2(root, 0)
