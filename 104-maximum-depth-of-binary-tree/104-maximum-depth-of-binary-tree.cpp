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
    
    void dfs(TreeNode* root, int &a, int &ans) {
        ans = max(ans,a);
        if(root -> left != NULL) {
            a += 1;
            dfs(root -> left, a, ans);
            a -= 1;
        }
        if(root -> right != NULL) {
            a += 1;
            dfs(root -> right, a, ans);
            a -= 1;
        }
     }
    
    int maxDepth(TreeNode* root) {
        if(root == NULL)
            return 0;
        int ans = 1, a = 1;
        dfs(root,a,ans);
        return ans;
        
    }
};