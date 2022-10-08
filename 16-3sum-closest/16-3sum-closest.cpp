class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int ans = nums[0] + nums[1] + nums[2];
        for(int i = 0; i < nums.size() - 2; i++) {
            for(int j = i+1; j < nums.size() - 1; j++) {
                int lb = upper_bound(nums.begin() + j + 1, nums.end(),target-nums[i]-nums[j]) - nums.begin();
                int that = lb, prev = lb - 1;
                if(that < nums.size()) {
                    if(abs(target-ans) > abs(target - nums[i] - nums[j] - nums[that])) {
                        ans = nums[i] + nums[j] + nums[that];
                    }
                }
                if(prev > j) {
                    if(abs(target-ans) > abs(target - nums[i] - nums[j] - nums[prev])) {
                        ans = nums[i] + nums[j] + nums[prev];
                    }
                }
                if(ans == target) {
                    return ans;
                }
            }
        }
        return ans;
    }
};