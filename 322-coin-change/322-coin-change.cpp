class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        
        if(amount == 0) {
            return 0;
        }
        
        vector<vector<int>> dp(coins.size() + 1, vector<int> (amount + 1,0));
        
        for(int i = 0; i < coins.size() + 1; i++) {
            for(int j = 0; j < amount + 1; j++) {
                dp[i][j] = 1e9;
            }
        }
        
        for(int i = 0; i < coins.size() + 1; i++) {
            dp[i][0] = 0;
        }
        
        sort(coins.begin(),coins.end());
        
        for(int i = 1; i <= coins.size(); i++) {
            for(int j = 1; j <= amount; j++) {
                
                if(i == 1) {
                    if(j % coins[i-1] == 0) {
                        dp[i][j] = j / coins[i-1];
                    }
                }
                else {
                    dp[i][j] = min(dp[i][j], dp[i-1][j]);
                    if(j - coins[i-1] >= 0) {
                        dp[i][j] = min(dp[i][j], dp[i][j - coins[i-1]] + 1);
                    }
                }
                
            }
        }
        if(dp[coins.size()][amount] >= 1e9) {
            return -1;
        }
        return dp[coins.size()][amount];
    }
};