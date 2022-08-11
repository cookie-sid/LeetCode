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
    
    vector<vector<int>> verticalOrder(TreeNode* root) {
        if(!root) {
            return {};
        }
        vector<vector<int>> ans;
        map<int,vector<int>> m;
        queue<pair<TreeNode*,int>> q;
        q.push(make_pair(root,0));
        while(!q.empty()) {
            int csize = q.size();
            for(int i = 0; i < csize; i++) {
                auto top = q.front();
                q.pop();
                m[top.second].push_back(top.first -> val);
                if(top.first -> left != NULL) {
                    q.push(make_pair(top.first -> left, top.second - 1));
                }
                if(top.first -> right != NULL) {
                    q.push(make_pair(top.first -> right, top.second + 1));
                }
            }
        }
        for(auto x : m) {
            ans.push_back(x.second);
        }
        return ans;
    }
};