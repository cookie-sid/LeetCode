class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        
        vector<int> freq(10001);
        for(auto x : nums) {
            freq[x]++;
        }
        
        vector<vector<int>> dp(10001, vector<int> (2,0));
        for(int i = 1; i < 10001; i++) {
            if(freq[i] == 0) {
                dp[i][0] = max(dp[i-1][0],dp[i-1][1]);
                dp[i][1] = max(dp[i-1][0],dp[i-1][1]);
            }
            else {
                dp[i][0] = max(dp[i-1][0],dp[i-1][1]);
                dp[i][1] = max(dp[i-1][0] + i * freq[i],dp[i-1][1]);
            }
        }
        return max(dp[10000][0],dp[10000][1]);
        
    }
};