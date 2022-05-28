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
    
    void dfs(TreeNode* root, vector<TreeNode*> &curr, map<TreeNode*, bool> &m) {
        if((root -> left == NULL and root -> right == NULL)) {
            curr.push_back(root);
            return;
        }
        if((root -> left == NULL and m[root -> right])) {
            curr.push_back(root);
            return;
        }
        if((m[root -> left] and root -> right == NULL)) {
            curr.push_back(root);
            return;
        }
        if((m[root -> left] and m[root -> right])) {
            curr.push_back(root);
            return;
        }
        if(root -> left != NULL and !m[root -> left]) {
            dfs(root -> left, curr, m);
        }
        if(root -> right != NULL and !m[root -> right]) {
            dfs(root -> right, curr, m);
        }
    }
    
    vector<vector<int>> findLeaves(TreeNode* root) {
        
        vector<vector<int>> ans;
        vector<TreeNode*> curr;
        map<TreeNode*, bool> m;
        while(!m[root]) {
            dfs(root,curr,m);
            vector<int> vals;
            for(auto x : curr) {
                vals.push_back(x -> val);
                m[x] = true;
            }
            ans.push_back(vals);
            curr.clear();
        }
        return ans;
    }
};