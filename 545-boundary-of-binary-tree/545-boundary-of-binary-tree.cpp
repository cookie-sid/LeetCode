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
    
    void getLeft(TreeNode* root, vector<int> &ans) {
        
        if(root == NULL or (root -> left == NULL and root -> right == NULL)) {
            return;
        }
        ans.push_back(root -> val);
        if(root -> left != NULL) {
            getLeft(root -> left,ans);
        }
        else {
            getLeft(root -> right,ans);
        }
        
    }
    
    void getLeaves(TreeNode* root, vector<int> &ans) {
        if(root == NULL) {
            return;
        }
        if(root -> left == NULL and root -> right == NULL) {
            ans.push_back(root -> val);
        }
        getLeaves(root -> left,ans);
        getLeaves(root -> right,ans);
    }
    
    void getRight(TreeNode* root, vector<int> &ans) {
        
        if(root == NULL or (root -> left == NULL and root -> right == NULL)) {
            return;
        }
        ans.push_back(root -> val);
        if(root -> right != NULL) {
            getRight(root -> right,ans);
        }
        else {
            getRight(root -> left,ans);
        }
        
    }
    
    vector<int> boundaryOfBinaryTree(TreeNode* root) {
        vector<int> ans;
        ans.push_back(root -> val);
        getLeft(root->left,ans);
        getLeaves(root -> left,ans);
        getLeaves(root -> right,ans);
        int x = ans.size();
        getRight(root -> right,ans);
        int first = x, last = ans.size() - 1;
        while(first < last) {
            int temp = ans[first];
            ans[first] = ans[last];
            ans[last] = temp;
            first++;
            last--;
        }
        return ans;
    }
};