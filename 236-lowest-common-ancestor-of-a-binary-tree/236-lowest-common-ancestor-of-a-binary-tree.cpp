/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    
    void dfs(TreeNode* root, vector<TreeNode*> &path, TreeNode* p, TreeNode *q, vector<vector<TreeNode*>> &paths) {
        path.push_back(root);
        if(root == p or root == q) {
            paths.push_back(path);
        }
        if(root -> left != NULL) {
            dfs(root -> left, path, p, q, paths);
        }
        if(root -> right != NULL) {
            dfs(root -> right, path, p, q, paths);
        }
        path.pop_back();
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<vector<TreeNode*>> paths;
        vector<TreeNode*> path;
        dfs(root,path,p,q,paths);
        int i = 0;
        while(i < paths[0].size() and i < paths[1].size() and paths[0][i] == paths[1][i]) {
            i++;
        }
        return paths[0][i-1];
    }
};