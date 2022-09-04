# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def verticalTraversal(self, root: Optional[TreeNode]) -> List[List[int]]:
        
        
        d = {}
        
        def dfs(root,row,col):
            if not root:
                return
            if col in d:
                if row in d[col]:
                    d[col][row].append(root.val)
                else:
                    d[col][row] = [root.val]
            else:
                d[col] = {}
                d[col][row] = [root.val]
                
            dfs(root.left,row+1,col-1)
            dfs(root.right,row+1,col+1)
            
        dfs(root,0,0)
        
        keys = list(d.keys())
        keys.sort()
        ans = []
        for key in keys:
            tk = list(d[key].keys())
            tk.sort()
            val = []
            for k in tk:
                val.extend(sorted(d[key][k]))
            ans.append(val)
            
        return ans