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
    
    void dfs(TreeNode* root, map<TreeNode*, bool> &m, vector<TreeNode*> &ans) {
        if(root -> left != NULL and !m[root -> left]) {
            dfs(root -> left,m,ans);
        }
        if(root -> right != NULL and !m[root -> right]) {
            dfs(root -> right,m,ans);
        }
        if((root -> left == NULL or m[root -> left]) and (root -> right == NULL or m[root -> right])) {
            ans.push_back(root);
        }
    }
    
    vector<vector<int>> findLeaves(TreeNode* root) {
        map<TreeNode*, bool> m;
        vector<vector<int>> ans;
        while(!m[root]) {
            vector<TreeNode*> tmp;
            dfs(root,m,tmp);
            vector<int> vals;
            for(auto node : tmp) {
                vals.push_back(node -> val);
                m[node] = true;
            }
            ans.push_back(vals);
        }
        return ans;
    }
};