/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        if(root == NULL or root == p or root == q)
            return root;
        
        auto left = lowestCommonAncestor(root -> left,p,q);
        auto right = lowestCommonAncestor(root -> right,p,q);
        
        if(left != NULL and right != NULL) {
            return root;
        }
        if(left == NULL)
            return right;
        else 
            return left;
        
        return p;
        
        
    }
};