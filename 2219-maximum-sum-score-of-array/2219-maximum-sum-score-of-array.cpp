class Solution {
public:
    long long maximumSumScore(vector<int>& nums) {
        long long sum = 0;
        for(auto x : nums) {
            sum += x;
        }
        long long ans = LLONG_MIN, leftsum = 0;
        for(int i = 0; i < nums.size(); i++) {
            leftsum += nums[i];
            ans = max(ans,max(leftsum,sum));
            sum -= nums[i];
        }
        return ans;
    }
};