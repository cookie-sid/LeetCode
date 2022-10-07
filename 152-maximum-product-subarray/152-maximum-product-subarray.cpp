class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        int n = nums.size();
        vector<pair<int,int>> dp(n);
        dp[0].first = nums[0];
        dp[0].second = nums[0];
        int maxi = nums[0];
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] < 0) {
                dp[i].first = max(dp[i-1].second * nums[i],nums[i]);
                dp[i].second = min(dp[i-1].first * nums[i],nums[i]);
            }
            else {
                dp[i].first = max(dp[i-1].first * nums[i],nums[i]);
                dp[i].second = min(dp[i-1].second * nums[i],nums[i]);
            }
            maxi = max(maxi,dp[i].first);
            maxi = max(maxi,dp[i].second);
        }
        return maxi;
        
    }
};