class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<vector<int>>> dp(strs.size() + 1, vector<vector<int>> (m + 1, vector<int>(n + 1)));
        for(int i = 1; i <= strs.size(); i++) {
            int cz = 0, co = 0;
            for(auto c : strs[i-1]) {
                if(c == '0')
                    cz++;
                else
                    co++;
            }
            for(int j = 0; j <= m; j++) {
                for(int k = 0; k <= n; k++) {
                    if(j - cz >= 0 and k - co >= 0) {
                        dp[i][j][k] = max(dp[i-1][j][k],max(dp[i][j][k],dp[i-1][j-cz][k-co] + 1));
                    }
                    else {
                        dp[i][j][k] = max(dp[i][j][k],dp[i-1][j][k]);
                    }
                }
            }
        }
        return dp[strs.size()][m][n];
    }
};