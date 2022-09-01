class Solution {
public:
    
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        vector<long long> dp(n);
        dp[n-1] = questions[n-1][0];
        for(int i = n - 2; i >= 0; i--) {
            if(questions[i][1] + i + 1 < n) {
                dp[i] = questions[i][0] + dp[questions[i][1] + i + 1];
            }
            else {
                dp[i] = questions[i][0];
            }
            dp[i] = max(dp[i+1],dp[i]);
        }
        return dp[0];
    }
};