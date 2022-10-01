class Solution:
    def numDecodings(self, s: str) -> int:
        n = len(s)
        dp = [0]*n
        for i in range(n):
            if i == 0:
                if(s[i] == "0"):
                    return 0
                else:
                    dp[i] = 1
            else:
                if(s[i] == "0"):
                    if(s[i-1] != "1" and s[i-1] != "2"):
                        return 0
                    else:
                        if i-2 >= 0:
                            dp[i] = dp[i-2]
                        else:
                            dp[i] = 1
                else:
                    dp[i] = dp[i-1]
                    if(s[i-1] != "0" and int(s[i-1:i+1]) <= 26):
                        if i-2 >= 0:
                            dp[i] += dp[i-2]
                        else:
                            dp[i] += 1
        
        return dp[n-1]