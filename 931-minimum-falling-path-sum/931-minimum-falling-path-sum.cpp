class Solution {
public:
    
    int recur(vector<vector<int>> &mat, int x, int y, int n, vector<vector<int>> &dp) {
        if(x >= n) {
            return 0;
        }
        if(y < 0 or y >= n) {
            return 1e9;
        }
        if(dp[x][y] != 1e9) {
            return dp[x][y];
        }
        int ans = 1e9;
        ans = min(ans,mat[x][y] + min(recur(mat,x+1,y-1,n,dp), min(recur(mat,x+1,y,n,dp),recur(mat,x+1,y+1,n,dp))));
        
        dp[x][y] = ans;
        return dp[x][y];
        
    }
    
    int minFallingPathSum(vector<vector<int>>& matrix) {
        
        int n = matrix.size();
        int ans = 1e9;
        vector<vector<int>> dp(n, vector<int> (n));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                dp[i][j] = 1e9;
            }
        }
        for(int i = 0; i < n; i++) {
            ans = min(ans,recur(matrix,0,i,n,dp));
        }
        // for(auto x : dp) {
        //     for(auto y : x) {
        //         cout<<y<<" ";
        //     }
        //     cout<<endl;
        // }
        return ans;
    }
};