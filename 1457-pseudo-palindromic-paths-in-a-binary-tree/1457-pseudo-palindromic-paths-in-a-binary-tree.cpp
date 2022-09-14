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
    
    bool check(vector<int> &ct) {
        int odd = 0, even = 0;
        for(auto x : ct) {
            if(x != 0) {
                if(x % 2 == 0)
                    even += 1;
                else
                    odd += 1;
            }
        }
        if(odd > 1) {
            return false;
        }
        return true;
    }
    
    void dfs(TreeNode* root, int &ans, vector<int> &ct) {
        if(root == NULL) {
            return;
        }
        if(root -> left == NULL and root -> right == NULL) {
            ct[root -> val] += 1;
            if(check(ct)) {
                ans += 1;
            }
            ct[root -> val] -= 1;
            return;
        }
        ct[root -> val] += 1;
        if(root -> left != NULL) {
            dfs(root -> left,ans,ct);
        }
        if(root -> right != NULL) {
            dfs(root -> right,ans,ct);
        }
        ct[root -> val] -= 1;
    }
    
    int pseudoPalindromicPaths (TreeNode* root) {
        vector<int> ct(10);
        int ans = 0;
        dfs(root,ans,ct);
        return ans;
    }
};