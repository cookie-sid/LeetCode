/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    bool check(TreeNode* root, int targetSum) {
        if(root == NULL) {
            return false;
        }
        if(root -> left == NULL and root -> right == NULL) {
            if(root -> val == targetSum) {
                return true;
            }
            return false;
        }
        return check(root -> left,targetSum - root->val) or check(root -> right,targetSum - root->val);
        
    }
    
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root == NULL) {
            return false;
        } 
        return check(root,targetSum);
    }
};