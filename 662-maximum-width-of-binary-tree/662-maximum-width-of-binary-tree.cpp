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
    
    int widthOfBinaryTree(TreeNode* root) {
        
        if(root == nullptr) return 0;
        queue<pair<TreeNode*, unsigned int>> q;
        q.push({root, 0});
        int maxWidth = 0;
        while(!q.empty()) {
            int len = q.size();
            pair<TreeNode*, unsigned int> front = q.front();
            pair<TreeNode*, unsigned int> elem;
            for(int i=0; i<len; i++) {
                elem = q.front();
                q.pop();
                if(elem.first->left != nullptr) {
                    q.push({elem.first->left, 2*elem.second});
                }
                if(elem.first->right != nullptr) {
                    q.push({elem.first->right, 2*elem.second + 1});
                }
            }
            maxWidth = max(maxWidth, (int) (elem.second - front.second + 1));
        }
        return maxWidth;
        
    }
};