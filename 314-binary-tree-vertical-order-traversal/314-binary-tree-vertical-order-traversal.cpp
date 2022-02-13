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
    
    // void dfs(TreeNode* root, int a, int &mini, int &maxi) {
    //     mini = min(mini,a);
    //     maxi = max(maxi,a);
    //     if(root -> left != NULL) {
    //         dfs(root -> left, a - 1, mini, maxi);
    //     }
    //     if(root -> right != NULL) {
    //         dfs(root -> right, a + 1, mini, maxi);
    //     }
    // }
    
    vector<vector<int>> verticalOrder(TreeNode* root) {
        if(root == NULL)
            return {};
        
        // int a = 0, mini = 1e9, maxi = -1e9;
        // dfs(root, a, mini, maxi);
        // int size = maxi - mini + 1;
        // mini = -mini;
        vector<vector<int>> ans;
        map<int,vector<int>> m;
        queue<pair<TreeNode*,int>> q;
        q.push(make_pair(root,0));
        while(!q.empty()) {
            int currlen = q.size();
            while(currlen > 0) {
                TreeNode* curr = q.front().first;
                if(curr -> left != NULL) {
                    q.push(make_pair(curr -> left, q.front().second - 1));
                }
                if(curr -> right != NULL) {
                    q.push(make_pair(curr -> right, q.front().second + 1));
                }
                m[q.front().second].push_back(curr -> val);
                q.pop();
                currlen--;
            }
        }
        for(auto x : m) {
            ans.push_back(x.second);
        }
        
        return ans;
        
    }
};