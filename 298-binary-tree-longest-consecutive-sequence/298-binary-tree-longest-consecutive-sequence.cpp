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
    
    int dfs(TreeNode* root, int n, int &ans) {
        ans = max(ans,n);
        if(root -> left != NULL and root -> left -> val == root -> val + 1) {
            dfs(root -> left, n + 1, ans);
        }
        if(root -> left != NULL and root -> left -> val != root -> val + 1) {
            dfs(root -> left, 1, ans);
        }
        if(root -> right != NULL and root -> right -> val == root -> val + 1) {
            dfs(root -> right, n + 1, ans);
        }
        if(root -> right != NULL and root -> right -> val != root -> val + 1) {
            dfs(root -> right, 1, ans);
        }
        return ans;
    }
    
    int longestConsecutive(TreeNode* root) {
        int ans = 1, n = 1;
        return dfs(root,n,ans);
    }
};