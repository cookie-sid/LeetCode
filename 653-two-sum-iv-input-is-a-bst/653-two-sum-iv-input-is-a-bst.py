# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def findTarget(self, root: Optional[TreeNode], target: int) -> bool:
        
        arr = []
        
        def trav(self,root):
            if not root:
                return
            trav(self,root.left)
            arr.append(root.val)
            trav(self,root.right)
            
        trav(self,root)
        start = 0
        end = len(arr) - 1
        while(start < end):
            if arr[start] + arr[end] < target:
                start += 1
            elif arr[start] + arr[end] > target:
                end -= 1
            else:
                return True
            
        return False