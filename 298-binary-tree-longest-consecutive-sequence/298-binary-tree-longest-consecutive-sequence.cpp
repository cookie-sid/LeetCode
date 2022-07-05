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
    
    int dfs(TreeNode* root, int val, int n, int &ans) {
        if(root == NULL) {
            return 0;
        }
        if(root -> val == val + 1) {
            n += 1;
        }
        else {
            n = 1;
        }
        ans = max(ans,n);
        dfs(root -> left, root -> val, n, ans);
        dfs(root -> right, root -> val, n, ans);
        return ans;
    }
    
    int longestConsecutive(TreeNode* root) {
        int ans = 1, n = 1;
        return dfs(root,root -> val,n,ans);
    }
};