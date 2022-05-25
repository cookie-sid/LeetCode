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
    
    int longest(TreeNode* root) {
        int maxi = 0;
        if(root -> left != NULL and root -> left -> val == root -> val) {
            maxi = max(maxi, 1 + longest(root -> left));
        }
        if(root -> right != NULL and root -> right -> val == root -> val) {
            maxi = max(maxi, 1 + longest(root -> right));
        }
        return maxi;
    }
    
    int longestUnivaluePath(TreeNode* root) {
        
        if(root == NULL) {
            return 0;
        }
        
        int maxi = 0;
        if(root -> left != NULL and root -> right != NULL) {
            if(root -> val == root -> left -> val and root -> val == root -> right -> val) {
                maxi = max(maxi, 2 + longest(root -> left) + longest(root -> right));
                maxi = max(maxi, longestUnivaluePath(root -> left));
                maxi = max(maxi, longestUnivaluePath(root -> right));
            }
            else if(root -> val == root -> left -> val and root -> val != root -> right -> val) {
                maxi = max(maxi, 1 + longest(root -> left));
                maxi = max(maxi, longestUnivaluePath(root -> left));
                maxi = max(maxi, longestUnivaluePath(root -> right));
                
            }
            else if(root -> val != root -> left -> val and root -> val == root -> right -> val) {
                maxi = max(maxi, 1 + longest(root -> right));
                maxi = max(maxi, longestUnivaluePath(root -> right));
                maxi = max(maxi, longestUnivaluePath(root -> left));
            }
            else {
                maxi = max(maxi,max(longestUnivaluePath(root -> right),longestUnivaluePath(root -> left)));
            }
        }
        else if(root -> left != NULL and root -> right == NULL) {
            if(root -> val == root -> left -> val) {
                maxi = max(maxi, 1 + longest(root -> left));
                maxi = max(maxi, longestUnivaluePath(root -> left));
            }
            else {
                maxi = max(maxi, longestUnivaluePath(root -> left));
            }
        }
        else if(root -> left == NULL and root -> right != NULL) {
            if(root -> val == root -> right -> val) {
                maxi = max(maxi, 1 + longest(root -> right));
                maxi = max(maxi, longestUnivaluePath(root -> right));
            }
            else {
                maxi = max(maxi,longestUnivaluePath(root -> right));
            }
        }
        return maxi;
    }
};