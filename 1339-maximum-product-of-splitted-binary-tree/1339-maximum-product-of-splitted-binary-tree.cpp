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
    
    void fillIt(TreeNode *root) {
        if(root == NULL) {
            return;
        }
        fillIt(root -> left);
        fillIt(root -> right);
        if(root -> left != NULL) {
            root -> val += root -> left -> val;
        }
        if(root -> right != NULL) {
            root -> val += root -> right -> val;
        }
    }
    
    void dfs(TreeNode* root, long long &ans, long long &total) {
        if(root == NULL) {
            return;
        }
        if(root -> left != NULL) {
            ans = max(ans,(total - root -> left -> val)*(root -> left -> val));
        }
        if(root -> right != NULL) {
            ans = max(ans,(total - root -> right -> val)*(root -> right -> val));
        }
        dfs(root -> left,ans,total);
        dfs(root -> right,ans,total);
    }
    
    int maxProduct(TreeNode* root) {
        TreeNode* tp = root;
        fillIt(tp);
        long long total = root -> val;
        int mod = 1e9 + 7;
        long long ans = 0;
        dfs(root,ans,total);
        return ans % mod;
    }
};