"""
# Definition for a Node.
class Node:
    def __init__(self, val=None, children=None):
        self.val = val
        self.children = children
"""

class Solution:
    def levelOrder(self, root: 'Node') -> List[List[int]]:
        if not root:
            return []
        ans = []
        q = []
        q.append(root)
        while len(q) != 0:
            size = len(q)
            thisLevel = []
            for i in range(0,size):
                top = q[0]
                thisLevel.append(top.val)
                q.pop(0)
                for c in top.children:
                    q.append(c)
            ans.append(thisLevel)
            
        return ans
                
                
        