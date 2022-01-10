class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = -1e9 - 9, sum = 0;
        for(int i= 0; i < nums.size(); i++) {
            sum = max(sum + nums[i],nums[i]);
            ans = max(ans,sum);
        }
        return ans;
    }
};