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
    
    TreeNode* findLast(TreeNode* root) {
        if(root -> left != NULL) {
            return findLast(root -> left);
        }
        return root;
    }
    
    void dfs(TreeNode* root) {
        if(root -> left == NULL and root -> right == NULL) {
            return;
        }
        if(root -> left != NULL) {
            if(root -> right == NULL) {
                dfs(root -> left);
            }
            else {
                dfs(root -> left);
                findLast(root) -> left = root -> right;
                root -> right = NULL;
                dfs(root -> left);
            }
        }
        else {
            root -> left = root -> right;
            root -> right = NULL;   
            dfs(root -> left);
        }
    }
    
    void diffDFS(TreeNode* root) {
        if(root -> left != NULL) {
            root -> right = root -> left;
            root -> left = NULL;
            diffDFS(root -> right);
        }
    }
    
    void print(TreeNode* root) {
        cout<<root -> val<<endl;
        if(root -> right != NULL) {
            print(root -> right);
        }
    }
    
    void flatten(TreeNode* root) {
        if(root == NULL) {
            return;
        }
        dfs(root);
        diffDFS(root);
    }
};