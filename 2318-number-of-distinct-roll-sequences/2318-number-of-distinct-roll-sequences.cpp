class Solution {
public:
    
    int gcd(int a, int b) {
        if(a % b == 0) {
            return b;
        }
        return gcd(b, a%b);
    }
    
    int distinctSequences(int n) {
        if(n == 1) {
            return 6;
        }
        vector<vector<int>> dp(4, vector<int>(7));
        for(int i = 1; i <= 6; i++) {
            for(int j = 1; j <= 6; j++) {
                if(i != j and gcd(i,j) == 1) {
                    dp[1][i] += 1;
                }
            }
        }
        for(int i = 1; i <= 6; i++) {
            dp[2][i] = dp[1][i];
        }
        int ans = 0, mod = 1e9 + 7;
        
        for(int k = 3; k <= n; k++) {
            
            vector<int> ct(7);
            for(int i = 1; i <= 6; i++) {
                for(int j = 1; j <= 6; j++) {
                    if(i != j and gcd(i,j) == 1) {
                        ct[i] += 1;
                        dp[3][i] += dp[2][j];
                        dp[3][i] %= mod;
                    }
                }
            }
            for(int i = 1; i <= 6; i++) {
                for(int j = 1; j <= 6; j++) {
                    if(i == j) {
                        dp[3][i] -= dp[1][i]%mod;
                        dp[3][i] %= mod;
                    }
                }
            }
            for(int i = 1; i <= 6; i++) {
                dp[1][i] = ((long long)(dp[2][i])%mod*(ct[i] - 1))%mod;
            }
            for(int i = 1; i <= 6; i++) {
                dp[2][i] = dp[3][i];
                dp[3][i] = 0;
            }
        }
        for(int i = 1; i <= 6; i++) {
            ans += dp[2][i]%mod;
            ans %= mod;
        }
        return (ans + mod)%mod;
    }
};