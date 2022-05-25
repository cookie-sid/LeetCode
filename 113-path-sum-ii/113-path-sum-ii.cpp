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
    
    void dfs(TreeNode* root, int &targetSum, int currSum, vector<int> &path, vector<vector<int>> &ans) {
        if(root -> left == NULL and root -> right == NULL and currSum + root -> val == targetSum) {
            path.push_back(root->val);
            ans.push_back(path);
            path.pop_back();
            return;
        }
        path.push_back(root->val);
        if(root -> left != NULL) {
            dfs(root -> left, targetSum, currSum + root -> val, path, ans);
        }
        if(root -> right != NULL) {
            dfs(root -> right, targetSum, currSum + root -> val, path, ans);
        }
        path.pop_back();
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> path;
        vector<vector<int>> ans;
        if(root == NULL)
            return ans;
        int currSum = 0;
        dfs(root,targetSum,currSum,path,ans);
        return ans;
    }
};