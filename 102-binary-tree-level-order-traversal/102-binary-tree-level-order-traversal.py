# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    
    def bfs(self, root: Optional[TreeNode]) -> List[List[int]]:
        final = []
        if(root == None) :
            return final
        ls = []
        ls.append(root)
        while(len(ls) > 0):
            vals = []
            size = len(ls)
            for i in range(0,size):
                curr = ls[0]
                vals.append(curr.val)
                if(curr.left != None):
                    ls.append(curr.left)
                if(curr.right != None):
                    ls.append(curr.right)
                ls.pop(0)
            final.append(vals)
            
        return final
                
            
        
            
        
        
    
    def levelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        return self.bfs(root)