class Solution {
public:
    int maximumScore(vector<int>& nums, vector<int>& mul) {
        int m = mul.size(), n = nums.size();
        vector<vector<int>> dp(m + 1, vector<int> (m + 1));
        
        int ans = -1e9;
        for(int i = 1; i <= m; i++) {
            dp[0][i] = dp[0][i-1] + mul[i-1]*nums[n-i];
            dp[i][0] = dp[i - 1][0] + mul[i-1]*nums[i-1];
        }
        ans = max(dp[m][0],dp[0][m]);
        for(int i = 1; i <= m; i++) {
            for(int j = 1; j <= (m - i); j++) {
                dp[i][j] = max(dp[i-1][j] + mul[i+j-1]*nums[i-1], dp[i][j-1] + mul[i+j-1]*nums[n - j]);
                if(i + j == m) {
                    ans = max(dp[i][j],ans);
                }
            }
        }
        return ans;
    }
};