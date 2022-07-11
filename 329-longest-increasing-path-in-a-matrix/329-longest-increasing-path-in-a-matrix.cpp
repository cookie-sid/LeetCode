class Solution {
public:
    
    bool valid(int i, int j, int n, int m) {
        return i >= 0 and i < n and j >= 0 and j < m;
    }
    
    int longest(vector<vector<int>> &matrix, int curri, int currj, int n, int m, vector<vector<int>> &dp) {
        
        if(dp[curri][currj] != 0) {
            return dp[curri][currj];
        }
        int maxi = 1;
        if(valid(curri+1,currj,n,m) and matrix[curri+1][currj] > matrix[curri][currj]) {
            maxi = max(maxi,1 + longest(matrix,curri + 1,currj,n,m,dp));
        }
        if(valid(curri-1,currj,n,m) and matrix[curri-1][currj] > matrix[curri][currj]) {
            maxi = max(maxi,1 + longest(matrix,curri - 1,currj,n,m,dp));
        }
        if(valid(curri,currj+1,n,m) and matrix[curri][currj+1] > matrix[curri][currj]) {
            maxi = max(maxi,1 + longest(matrix,curri,currj + 1,n,m,dp));
        }
        if(valid(curri,currj-1,n,m) and matrix[curri][currj-1] > matrix[curri][currj]) {
            maxi = max(maxi,1 + longest(matrix,curri,currj - 1,n,m,dp));
        }
        dp[curri][currj] = maxi;
        return maxi;
        
    }
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<int>> dp(n, vector<int> (m));
        int maxi = 1;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(dp[i][j] == 0) {
                    dp[i][j] = longest(matrix,i,j,n,m,dp);
                }
                maxi = max(maxi,dp[i][j]);
            }
        }
        return maxi;
    }
};