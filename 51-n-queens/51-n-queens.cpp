class Solution {
public:
    
    void recurr(vector<bool> &diag1, vector<bool> &diag2, vector<bool> &row, 
                vector<vector<string>> &ans, vector<string> &curr, int n, int x) {
        
        if(x == n) {
            ans.push_back(curr);
            return;
        }
        
        for(int i = 0; i < n; i++) {
            if(row[i] or diag1[i - x + n - 1] or diag2[i + x])
                continue;
            curr[i][x] = 'Q';
            row[i] = true;
            diag1[i - x + n - 1] = true;
            diag2[i + x] = true;
            recurr(diag1,diag2,row,ans,curr,n,x + 1);
            curr[i][x] = '.';
            row[i] = false;
            diag1[i - x + n - 1] = false;
            diag2[i + x] = false;
        }
        
    }
    
    vector<vector<string>> solveNQueens(int n) {
        vector<bool> diag1(2 * (n - 1) + 1), diag2(2 * (n - 1) + 1), row(n);
        vector<vector<string>> ans;
        vector<string> curr;
        for(int i = 0; i < n; i++) {
            string s = "";
            for(int j = 0; j < n; j++) {
                s += '.';
            }
            curr.push_back(s);
        }
        recurr(diag1, diag2, row, ans, curr, n, 0);
        return ans;
    }
};