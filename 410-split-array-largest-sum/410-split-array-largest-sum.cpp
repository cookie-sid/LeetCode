class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        int n = nums.size();
        vector<int> prefSum(n);
        prefSum[0] = nums[0];
        for(int i = 1; i < n; i++) {
            prefSum[i] += prefSum[i-1] + nums[i];
        }
        if(m == 1) {
            return prefSum[n-1];
        }
        vector<vector<int>> dp(m + 1, vector<int>(n));
        for(int i = 0; i < n; i++) {
            dp[1][i] = prefSum[i];
        }
        for(int i = 2; i <= m; i++) {
            int prev = i - 1;
            for(int j = i - 1; j < n; j++) {
                dp[i][j] = INT_MAX;
                for(int k = prev - 1; k < j; k++) {
                    dp[i][j] = min(dp[i][j], max(dp[i-1][k],prefSum[j] - prefSum[k]));
                }
            }
        }
        return dp[m][n-1];
    }
};