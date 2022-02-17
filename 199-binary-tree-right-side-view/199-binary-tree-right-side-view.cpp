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
    
    void dfs(TreeNode* root, int level, vector<int> &v) {
        if(root == NULL)
            return;
        if((int)v.size() - 1 < level) {
            v.push_back(root -> val);
        }
        if(root -> right != NULL) {
            dfs(root -> right, level + 1, v);
        }
        if(root -> left != NULL) {
            dfs(root -> left, level + 1, v);
        }
    }
    
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        dfs(root,0,ans);
        return ans;
    }
};