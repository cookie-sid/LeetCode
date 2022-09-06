# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    
    def pruneTree(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        
        def check(root):
            if not root:
                return False
            if root.val == 1:
                return True
            else:
                return check(root.left) or check(root.right)
        
        def dfs(root):
            if not root:
                return
            if not check(root.left):
                root.left = None
            else:
                dfs(root.left)
            if not check(root.right):
                root.right = None
            else:
                dfs(root.right)
        
        if not check(root):
            return None
        
        dfs(root)
        return root
                
                