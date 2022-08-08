class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size(),maxi = 1;
        vector<int> dp(n + 1,1e9);
        dp[0] = -1e9;
        
        for(int i = 0; i < n; i++) {
            int lower = lower_bound(dp.begin(),dp.end(),nums[i]) - dp.begin();
            dp[lower] = nums[i];
        }
        
        for(int i = 1; i <= n; i++) {
            if(dp[i] < 1e9) {
                maxi = i;
            }
        }
        return maxi;
    }
};