class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_map<int,int> m;
        int n = nums.size();
        vector<int> sum(n);
        int ans = nums[0];
        sum[0] = nums[0];
        m[nums[0]] = 1;
        int start = 0;
        for(int i = 1; i < n; i++) {
            sum[i] += nums[i] + sum[i-1];
            if(m[nums[i]] == 0) {
                int add = start > 0 ? sum[start - 1] : 0;
                ans = max(sum[i] -  add,ans);
            }
            if(m[nums[i]] != 0) {
                int sub = start > m[nums[i]] ? start = start : start = m[nums[i]];
                ans = max(sum[i] - sum[start - 1], ans);
            }
            m[nums[i]] = i + 1;
        }
        return ans;
    }
};