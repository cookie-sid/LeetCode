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
    
    int dfs(TreeNode* root, int n, unordered_map<TreeNode*, int> &m, int &ans) {
        if(m[root] != 0) {
            return m[root];
        }
        m[root] = max(m[root],n);
        ans = max(ans,m[root]);
        if(root -> left != NULL and root -> left -> val == root -> val + 1) {
            dfs(root -> left, m[root] + 1, m, ans);
        }
        if(root -> left != NULL and root -> left -> val != root -> val + 1) {
            dfs(root -> left, 1, m, ans);
        }
        if(root -> right != NULL and root -> right -> val == root -> val + 1) {
            dfs(root -> right, m[root] + 1, m, ans);
        }
        if(root -> right != NULL and root -> right -> val != root -> val + 1) {
            dfs(root -> right, 1, m, ans);
        }
        return ans;
    }
    
    int longestConsecutive(TreeNode* root) {
        int ans = 1;
        unordered_map<TreeNode*, int> m;
        return dfs(root,1,m,ans);
    }
};