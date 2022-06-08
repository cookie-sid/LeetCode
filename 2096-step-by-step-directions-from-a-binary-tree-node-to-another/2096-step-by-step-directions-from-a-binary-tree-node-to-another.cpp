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
    
    void getPath(TreeNode* root, int val, vector<TreeNode*> &path) {
        path.push_back(root);
        if(root -> val == val) {
            return;
        }
        if(root -> left != NULL) {
            getPath(root -> left, val, path);
        }
        if(root -> right != NULL) {
            getPath(root -> right, val, path);
        }
        if(path.size() != 0 and path.back() -> val == val) {
            return;
        }
        path.pop_back();
    }
    
    string getDirections(TreeNode* root, int startValue, int destValue) {
        vector<TreeNode*> forstart, fordest;
        getPath(root,startValue,forstart);
        getPath(root,destValue,fordest);
        int ctr = 0;
        string ans = "";
        while(ctr < forstart.size() and ctr < fordest.size() and forstart[ctr] == fordest[ctr]) {
            ctr++;
        }
        for(int i = 0; i < forstart.size() - ctr; i++) {
            ans += "U";
        }
        for(int i = ctr - 1; i < fordest.size() - 1; i++) {
            if(fordest[i] -> left != NULL and fordest[i] -> left -> val == fordest[i + 1] -> val) {
                ans += "L";
            }
            else {
                ans += "R";
            }
        }
        return ans;
    }
};