class Solution {
public:
    
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        
        int n = stations.size();
        vector<long long> dp(n + 1);
        dp[0] = startFuel;
        for(int i = 0; i < stations.size(); i++) {
            int maxi = -1;
            for(int j = i; j >= 0; j--) {
                if(dp[j] >= stations[i][0])
                    dp[j + 1] = max(dp[j + 1], dp[j] + stations[i][1]);
            }
        }
        for(int i = 0; i <= n; i++) {
            if(dp[i] >= target)
                return i;
        }
        return -1;
        
    }
};