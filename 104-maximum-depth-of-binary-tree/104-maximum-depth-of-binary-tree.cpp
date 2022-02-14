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
    
    void dfs(TreeNode* root, int a, int &ans) {
        ans = max(ans,a);
        if(root -> left != NULL) {
            dfs(root -> left, a + 1, ans);
        }
        if(root -> right != NULL) {
            dfs(root -> right, a + 1, ans);
        }
     }
    
    int maxDepth(TreeNode* root) {
        if(root == NULL)
            return 0;
        int ans = 1;
        dfs(root,1,ans);
        return ans;
        
    }
};