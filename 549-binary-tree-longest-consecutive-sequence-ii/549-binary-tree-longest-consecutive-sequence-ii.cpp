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
    
    void onlyIncr(TreeNode* root, int val, int n, int &ans) {
        if(root == NULL) {
            return;
        }
        if(root -> val == val + 1) {
            n += 1;
            ans = max(ans,n);
            onlyIncr(root -> left, root -> val, n, ans);
            onlyIncr(root -> right, root -> val, n, ans);
        }
        else {
            ans = max(ans,n);
        }
    }
    
    void onlyDecr(TreeNode* root, int val, int n, int &ans) {
        if(root == NULL) {
            return;
        }
        if(root -> val == val - 1) {
            n += 1;
            ans = max(ans,n);
            onlyDecr(root -> left, root -> val, n, ans);
            onlyDecr(root -> right, root -> val, n, ans);
        }
        else {
            ans = max(ans,n);
        }
    }
    
    int dfs(TreeNode* root, int &ans) {
        if(root == NULL) {
            return 0;
        }
        int lansI = 0, lansD = 0, ransI = 0, ransD = 0;
        onlyIncr(root -> left,root -> val,1,lansI);
        onlyDecr(root -> left,root -> val,1,lansD);
        onlyIncr(root -> right,root -> val,1,ransI);
        onlyDecr(root -> right,root -> val,1,ransD);
        ans = max(ans,lansI);
        ans = max(ans,lansD);
        ans = max(ans,ransI);
        ans = max(ans,ransD);
        ans = max(ans,lansI + ransD - 1);
        ans = max(ans,ransI + lansD - 1);
        dfs(root -> left, ans);
        dfs(root -> right, ans);
        return ans;
    }
    
    int longestConsecutive(TreeNode* root) {
        int ans = 1;
        dfs(root,ans);
        return ans;
    }
};