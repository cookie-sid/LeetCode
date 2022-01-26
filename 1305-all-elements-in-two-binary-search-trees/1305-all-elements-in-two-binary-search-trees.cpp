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
    
    void traverse(TreeNode* root, vector<int>& curr) {
        if(root == NULL) {
            return;
        }
        if(root -> left != NULL) {
            traverse(root -> left,curr);
        }
        curr.push_back(root -> val);
        if(root -> right != NULL) {
            traverse(root -> right,curr);
        }
    }
    
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> first;
        traverse(root1,first);
        vector<int> second;
        traverse(root2,second);
        vector<int> comb;
        int ptr_1 = 0, ptr_2 = 0;
        while(ptr_1 < first.size() and ptr_2 < second.size()) {
            if(first[ptr_1] > second[ptr_2]) {
                comb.push_back(second[ptr_2]);
                ptr_2++;
            }
            else {
                comb.push_back(first[ptr_1]);
                ptr_1++;
            }
        }
        while(ptr_1 < first.size()) {
            comb.push_back(first[ptr_1]);
            ptr_1++;
        }
        while(ptr_2 < second.size()) {
            comb.push_back(second[ptr_2]);
            ptr_2++;
        }
        return comb;
    }
};