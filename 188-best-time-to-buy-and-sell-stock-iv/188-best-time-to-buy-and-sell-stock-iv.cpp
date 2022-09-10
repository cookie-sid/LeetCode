class Solution {
public:
    int maxProfit(int m, vector<int>& prices) {
        int n = prices.size();
        if(n == 0 or m == 0) {
            return 0;
        }
        vector<vector<int>> dp(m+1, vector<int> (n + 1));
        
        for(int j = 1; j <=n; j++) {
            dp[0][j] -= prices[j-1];
            // cout<<dp[0][j]<<" ";
        }
        // cout<<endl;
        
        for(int i = 1; i <= m; i++) {
            int maxi = dp[i-1][1];
            for(int j = 2; j <= n; j++) {
                dp[i][j] = max(dp[i][j],maxi + prices[j-1]);
                dp[i][j] = max(max(dp[i-1][j] + prices[j-1],dp[i][j-1]),dp[i][j]);
                maxi = max(maxi,dp[i-1][j]);
            }
            if(i == m) {
                continue;
            }
            for(int j = 1; j <= n; j++) {
                // cout<<dp[i][j]<<" ";
                dp[i][j] -= prices[j-1];
            }
            // cout<<endl;
        }
        /*
         
        */
        // for(auto x : dp) {
        //     for(auto y : x) {
        //         cout<<y<<" ";
        //     }
        //     cout<<endl;
        // }
        return dp[m][n];
    }
};