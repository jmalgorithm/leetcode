# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def inorderTraversal(self, root):
        stack = []
        res = []
        pointer = root
        stack.append(pointer)
        while(len(stack)!=0 and pointer is not None):

            if(pointer.left is not None):
                pointer = pointer.left
                stack.append(pointer)
                #print(stack)
            elif(pointer.right is not None):
                res.append(stack.pop().val)
                #print(stack)
                #print(res)
                pointer = pointer.right
                stack.append(pointer)
            else:
                #print("both None", len(stack), pointer.right is None)
                while(len(stack)!=0 and pointer.right is None):
                    pointer = stack.pop()
                    res.append(pointer.val)
                    #print(res)
                    #print(stack)
                if(pointer.right is not None):
                    pointer=pointer.right
                    stack.append(pointer)
                    #print(stack)
        return res
