# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def inorderTraversal(self, root: TreeNode) -> List[int]:
        ls = []
        if root is None:
            pass
        else:
            ls += self.inorderTraversal(root.left)
            ls.append(root.val)
            ls += self.inorderTraversal(root.right)
        return ls
