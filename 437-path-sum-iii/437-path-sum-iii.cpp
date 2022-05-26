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
    
    void dfs(TreeNode* root, int &targetSum, long long currSum, long long &ans, map<long long, long long> &m) {
        if(m[currSum + root -> val - targetSum] != 0) {
            ans += m[currSum + root -> val - targetSum];
        }
        m[currSum + root -> val] += 1;
        if(root -> left != NULL) {
            dfs(root -> left,targetSum,currSum + root -> val, ans, m);
        }
        if(root -> right != NULL) {
            dfs(root -> right,targetSum,currSum + root -> val, ans, m);
        }
        m[currSum + root -> val] -= 1;
        
    }
    
    int pathSum(TreeNode* root, int targetSum) {
        if(root == NULL) {
            return 0;
        }
        map<long long,long long> m;
        m[0] = 1;
        long long ans = 0;
        dfs(root,targetSum,0LL,ans,m);
        return ans;
    }
};