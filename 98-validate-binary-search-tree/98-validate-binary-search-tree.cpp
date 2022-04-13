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
    
    void dfs(TreeNode* root, vector<int> &tree) {
        if(root -> left == NULL) {
            tree.push_back(root -> val);
        }
        if(root -> left != NULL) {
            dfs(root -> left, tree);
            tree.push_back(root -> val);
            
        }
        if(root -> right != NULL) {
            dfs(root -> right, tree);
        }
    }
    
    bool isValidBST(TreeNode* root) {
        vector<int> tree;
        dfs(root, tree);
        for(int i = 1; i < tree.size(); i++) {
            if(tree[i] <= tree[i-1]) {
                return false;
            }
        }
        return true;
    }
};