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
    
    void dfs(TreeNode* &root, vector<int> &ans) {
        bool pres = false;
        if(root -> left != NULL) {
            pres = true;
            dfs(root -> left,ans);
        }
        if(root -> right != NULL) {
            pres = true;
            dfs(root -> right,ans);
        }
        if(!pres and ((root -> left == NULL) and (root -> right == NULL))) {
            ans.push_back(root -> val);
            root = NULL;
        }
    }
    
    vector<vector<int>> findLeaves(TreeNode* root) {
        map<TreeNode*, bool> m;
        vector<vector<int>> ans;
        while(root != NULL) {
            vector<int> vals;
            dfs(root,vals);
            ans.push_back(vals);
        }
        return ans;
    }
};