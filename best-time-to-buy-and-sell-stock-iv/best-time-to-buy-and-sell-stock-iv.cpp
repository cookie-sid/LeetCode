class Solution {
public:
    
    int maxProfit(int k, vector<int>& prices) {
        if(prices.size() <= 1 or k == 0) {
            return 0;
        }
        
        int dp[k+1][prices.size()];
        for(int i = 0; i < k+1; i++) {
            for(int j = 0; j < prices.size(); j++)
            {
                dp[i][j] = 0;
            }
        }
        
        int mintillnow = prices[0];
        for(int i = 1; i < prices.size(); i++) {
            dp[1][i] = max(0,prices[i] - mintillnow);
            mintillnow = min(prices[i],mintillnow);
            dp[1][i] = max(dp[1][i-1],dp[1][i]);
        }
        
        for(int i = 2; i <= k; i++) {
            int maxdiff = -1e9;
            for(int j = 1; j < prices.size(); j++) {
                dp[i][j] = max(dp[i-1][j], maxdiff + prices[j]);
                dp[i][j] = max(dp[i][j-1],dp[i][j]);
                maxdiff = max(maxdiff,dp[i-1][j] - prices[j]);
                
            }
        }
        

        
        return dp[k][prices.size() - 1];
    }
};