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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        
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
            map<int,vector<int>> temp;
            while(currlen > 0) {
                TreeNode* curr = q.front().first;
                if(curr -> left != NULL) {
                    q.push(make_pair(curr -> left, q.front().second - 1));
                }
                if(curr -> right != NULL) {
                    q.push(make_pair(curr -> right, q.front().second + 1));
                }
                temp[q.front().second].push_back(curr -> val);
                q.pop();
                currlen--;
            }
            for(auto x : temp) {
                vector<int> bruh = x.second;
                sort(bruh.begin(),bruh.end());
                for(auto y : bruh) {
                    m[x.first].push_back(y);
                }
            }
        }
        for(auto x : m) {
            ans.push_back(x.second);
        }
        
        return ans;
        
    }
};