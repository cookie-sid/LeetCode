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
    
    void finder(TreeNode* tree, TreeNode* target, vector<int> &go, bool &temp) {
        if(tree == target) {
            temp = true;
            return;
        }
        if(!temp and tree -> left != NULL) {
            go.push_back(-1);
            finder(tree -> left, target, go, temp);
            if(temp) {
                return;
            }
            go.pop_back();
        }
        if(!temp and tree -> right != NULL) {
            go.push_back(1);
            finder(tree -> right, target, go, temp);
            if(temp) {
                return;
            }
            go.pop_back();
        }
    }
    
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        
        vector<int> path;
        bool ans = false;
        finder(original, target, path, ans);
        
        for(auto x : path) {
            if(x == -1) {
                cloned = cloned -> left;
            }
            else {
                cloned = cloned -> right;
            }
        }
        
        return cloned;
    }
};