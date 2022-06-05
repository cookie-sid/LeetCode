class Solution {
public:
    
    void recurr(vector<bool> &diag1, vector<bool> &diag2, vector<bool> &row, 
                int &ans, int n, int x) {
        
        if(x == n) {
            ans++;
            return;
        }
        
        for(int i = 0; i < n; i++) {
            if(row[i] or diag1[i - x + n - 1] or diag2[i + x])
                continue;
            row[i] = true;
            diag1[i - x + n - 1] = true;
            diag2[i + x] = true;
            recurr(diag1,diag2,row,ans,n,x + 1);
            row[i] = false;
            diag1[i - x + n - 1] = false;
            diag2[i + x] = false;
        }
        
    }
    
    int totalNQueens(int n) {
        vector<bool> diag1(2 * (n - 1) + 1), diag2(2 * (n - 1) + 1), row(n);
        int ans = 0;
        recurr(diag1, diag2, row, ans, n, 0);
        return ans;
    }
};