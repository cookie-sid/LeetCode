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
    
    void dfs(TreeNode* root, int total, int target, vector<int> &path, vector<vector<int>> &ans) {
        if(root -> left == NULL and root -> right == NULL) {
            if(total == target) {
                ans.push_back(path);
            }
            return;
        }
        if(root->left != NULL) {
            path.push_back(root->left->val);
            dfs(root->left,total + root->left->val,target, path,ans);
            path.pop_back();
        }
        if(root->right != NULL) {
            path.push_back(root->right->val);
            dfs(root->right,total + root->right->val,target, path,ans);
            path.pop_back();
        }
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if(root == NULL) {
            return {};
        }
        vector<int> path;
        vector<vector<int>> ans;
        int total = root->val;
        path.push_back(root->val);
        dfs(root,total,targetSum,path,ans);
        return ans;
    }
};