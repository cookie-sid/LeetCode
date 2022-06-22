class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.length(), m = word2.length();
        vector<vector<int>> dp(n + 1, vector<int> (m + 1));
        for(int i = 0; i < n + 1; i++) {
            dp[i][0] = i;
        }
        for(int i = 0; i < m + 1; i++) {
            dp[0][i] = i;
        }
        for(int i = 1; i <= n; i++) {
            for(int j = 1;  j <= m; j++) {
                dp[i][j] = min(dp[i-1][j] + 1, 
                               min(dp[i][j-1] + 1,word1[i-1] == word2[j-1] ? dp[i-1][j-1] : dp[i-1][j-1] + 1));
            }
        }
        return dp[n][m];
    }
};