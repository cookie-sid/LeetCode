class Solution {
public:
    
    int recurr(vector<vector<int>> &dp, vector<int> &nums, vector<int> &multipliers, int curr, int left, int m) {
        
        if(curr == m) {
            return 0;
        }
        
        int mult = multipliers[curr];
        int right = nums.size() - 1 - (curr - left);
        
        if(dp[curr][left] == 0) {
            dp[curr][left] = max(mult * nums[left] + recurr(dp,nums,multipliers,curr + 1,left + 1,m), mult * nums[right] + recurr(dp,nums,multipliers,curr + 1,left,m));
        }
        
        return dp[curr][left];
        
    }
    
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        
        int m = multipliers.size();
        vector<vector<int>> dp(m, vector<int> (m,0));
        return recurr(dp,nums,multipliers,0,0,m);
        
    }
};