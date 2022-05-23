class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> dp(coins.size() + 1, vector<int> (amount + 1));
        int n = coins.size();
        
        for(int i = 1; i <= amount; i++) {
            dp[0][i] = 1e9;
        }
        
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= amount; j++) {
                if(coins[i-1] <= j) {
                    dp[i][j] = min(dp[i-1][j],dp[i][j-coins[i-1]] + 1);
                }
                else {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        if(dp[n][amount] == 1e9) {
            return -1;
        }
        return dp[n][amount];
        
    }
};