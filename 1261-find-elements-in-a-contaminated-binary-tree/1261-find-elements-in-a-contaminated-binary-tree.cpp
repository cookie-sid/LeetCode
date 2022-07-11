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
class FindElements {
public:
    
    TreeNode* rt;
    
    void fillAll(TreeNode* root, int val) {
        if(root == NULL) {
            return;
        }
        root->val = val;
        fillAll(root -> left, 2*val + 1);
        fillAll(root -> right, 2*val + 2);
    }
    
    bool findIt(TreeNode* rt, int target) {
        if(rt == NULL) {
            return false;
        }
        if(rt -> val == target) {
            return true;
        }
        return findIt(rt -> left,target) or findIt(rt -> right,target);
    }
    
    FindElements(TreeNode* root) {
        rt = root;
        fillAll(root,0);
    }
    
    bool find(int target) {
        TreeNode* tp = rt;
        return findIt(tp,target);
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */