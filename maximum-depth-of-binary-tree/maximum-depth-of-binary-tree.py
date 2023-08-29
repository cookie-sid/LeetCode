# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def maxDepth(self, root: Optional[TreeNode]) -> int:
        
        if not root:
            return 0
        
        maxDepth = 1
        vis = set()
        def dfs(root,currDepth):
            vis.add(root)
            nonlocal maxDepth
            maxDepth = max(maxDepth,currDepth)
            if root.left and root.left not in vis:
                dfs(root.left,currDepth+1)
            if root.right and root.right not in vis:
                dfs(root.right,currDepth+1)
        
        dfs(root,1)
            
        return maxDepth
        