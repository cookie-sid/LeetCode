class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        map<int,int> m;
        map<int,int> dp;
        int maxi = 0;
        for(auto x : nums) {
            m[x] = 1;
        }
        for(auto x : m) {
            dp[x.first] = dp[x.first - 1] + 1;
            maxi = max(maxi,dp[x.first]);
        }
        return maxi;
    }
};