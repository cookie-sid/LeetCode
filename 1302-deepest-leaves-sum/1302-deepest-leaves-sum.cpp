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
    int deepestLeavesSum(TreeNode* root) {
        queue<TreeNode*> q;
        if(root == NULL) {
            return 0;
        }
        q.push(root);
        int prevsum = -1;
        while(!q.empty()) {
            int currsize = q.size();
            int sum = 0;
            for(int i = 0; i < currsize; i++) {
                sum += q.front() -> val;
                if(q.front() -> left != NULL) {
                    q.push(q.front() -> left);
                }
                if(q.front() -> right != NULL) {
                    q.push(q.front() -> right);
                }
                q.pop();
            }
            prevsum = sum;
        }
        return prevsum;
    }
};