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
        q = [root]
        vis = set()
        vis.add(root)
        depth = 0
        while len(q) != 0:
            s = len(q)
            for i in range(s):
                top = q[0]
                q.pop(0)
                if top.left and top.left not in vis:
                    q.append(top.left)
                    vis.add(top.left)
                if top.right and top.right not in vis:
                    q.append(top.right)
                    vis.add(top.right)
            depth += 1

        return depth
        