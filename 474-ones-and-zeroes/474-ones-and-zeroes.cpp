class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));
        for(int i = 1; i <= strs.size(); i++) {
            int cz = 0, co = 0;
            for(auto c : strs[i-1]) {
                if(c == '0')
                    cz++;
                else
                    co++;
            }
            for(int j = m; j >= 0; j--) {
                for(int k = n; k >= 0; k--) {
                    if(j - cz >= 0 and k - co >= 0) {
                        dp[j][k] = max(dp[j][k],dp[j-cz][k-co] + 1);
                    }
                    else {
                        dp[j][k] = max(dp[j][k],dp[j][k]);
                    }
                }
            }
        }
        return dp[m][n];
    }
};