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
    
    void dfs(vector<TreeNode*> &v, TreeNode* root, TreeNode* p, bool &found) {
        if(root == p or found) {
            found = true;
            return;
        }
        if(root != p) {
            v.push_back(root);
        }
        if(root -> left != NULL) {
            dfs(v,root -> left,p,found);
            if(!found)
                v.pop_back();
        }
        if(root -> right != NULL) {
            dfs(v,root -> right,p,found);
            if(!found)
                v.pop_back();
        }
        
        
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        vector<TreeNode*> pathP,pathQ;
        bool found = false;
        dfs(pathP,root,p,found);
        pathP.push_back(p);
        found = false;
        dfs(pathQ,root,q,found);
        pathQ.push_back(q);
        unordered_map<TreeNode*,int> pnodes;
        for(auto x : pathP) {
            pnodes[x] = 1;
        }
        for(int j = (int) pathQ.size() - 1; j >= 0; j --) {
            if(pnodes[pathQ[j]] == 1) {
                return pathQ[j];
            }
        }
        return root;
        
    }
};