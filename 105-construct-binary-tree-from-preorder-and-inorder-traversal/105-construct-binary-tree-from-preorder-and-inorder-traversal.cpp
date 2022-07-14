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
    
    
    
    int findIncr(vector<int>& arr, int a, int start, int end, vector<bool> &taken) {
        for(int i = start; i < end and !taken[i]; i++) {
            if(arr[i] == a and !taken[i]) {
                return i;
            }
        }
        return -1;
    }
    
    int findDecr(vector<int>& arr, int a, int start, int end, vector<bool> &taken) {
        for(int i = start; i >= end and !taken[i]; i--) {
            if(arr[i] == a and !taken[i]) {
                return i;
            }
        }
        return -1;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        TreeNode* t = new TreeNode(preorder[0]);
        TreeNode* root = t;
        if(preorder.size() == 1) {
            return t;
        }
        
        int n = preorder.size();
        vector<bool> taken(n);
        int rootInd = findIncr(inorder,preorder[0],0,n,taken);
        taken[rootInd] =  true;
        stack<pair<TreeNode*,int>> s;
        s.push(make_pair(t,rootInd));
        for(int i = 1; i < preorder.size() and s.size() != 0; i++) {
            rootInd = s.top().second;
            int leftInd = findDecr(inorder,preorder[i],rootInd-1,0,taken);
            if(leftInd != -1) {
                taken[leftInd] = true;
                s.top().first -> left = new TreeNode(preorder[i]);
                s.push(make_pair(s.top().first -> left,leftInd));
                continue;
            }
            int rightInd = findIncr(inorder,preorder[i],rootInd+1,n,taken);
            if(rightInd != -1) {
                taken[rightInd] = true;
                TreeNode* temp = new TreeNode(preorder[i]);
                s.top().first -> right = temp;
                s.pop();
                s.push(make_pair(temp,rightInd));
                continue;
            }
            if(rightInd == -1 and leftInd == -1) {
                i--;
                s.pop();
            }
        }
        return root;
    }
    
};