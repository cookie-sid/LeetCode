class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans(nums.size(),1);
        int from_start = 1, from_end = 1;
        for(int i = 0; i < ans.size(); i++) {
            ans[i] *= from_start;
            from_start *= nums[i];
            ans[nums.size() - 1 - i] *= from_end;
            from_end *= nums[nums.size() - i - 1];
        }
        return ans;
    }
};