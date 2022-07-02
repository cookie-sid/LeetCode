class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) {
            return nums[0];
        }
        if(n == 2) {
            return max(nums[0],nums[1]);
        }
        vector<vector<int>> dp(n, vector<int> (2));
        dp[0][0] = 0;
        dp[0][1] = 0;
        for(int i = 1; i < n; i++) {
            dp[i][0] = max(dp[i-1][0],dp[i-1][1]);
            dp[i][1] = dp[i-1][0] + nums[i];
        }
        int maxi = max(dp[n-1][0],dp[n-1][1]);
        dp[0][0] = -1e9;
        dp[0][1] = nums[0];
        for(int i = 1; i < n - 1; i++) {
            dp[i][0] = max(dp[i-1][0],dp[i-1][1]);
            dp[i][1] = dp[i-1][0] + nums[i];
        }
        return max(maxi,max(dp[n-2][0],dp[n-2][1]));
    }
};