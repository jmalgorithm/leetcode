# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
class Solution:
    def inorderTraversal(self, root):
        result=[]
        if(root == None):
            return result
        elif(root.val =="null"):
            return result
        else:
            if(root.left !="null" and root.left != None):
                result.extend(self.inorderTraversal(root.left))
                result.append(root.val)
                if(root.right !="null" and root.right != None):
                    result.extend(self.inorderTraversal(root.right))
                    return result
                else:
                    return result
            
            elif(root.right !="null" and root.right != None):
                result.append(root.val)
                result.extend(self.inorderTraversal(root.right))
                return result
            else:
                result.append(root.val)
                return result

        