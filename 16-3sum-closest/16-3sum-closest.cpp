class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        
        sort(nums.begin(),nums.end());
        
        int ans = nums[0] + nums[1] + nums[2];
        for(int i = 0; i < nums.size() - 2; i++) {
            for(int j = i  + 1; j < nums.size() - 1; j++) {
               
                int required = target - nums[i] - nums[j];
                int upper = upper_bound(nums.begin() + j + 1,nums.end(),required) - nums.begin();
                if(upper == nums.size()) {
                    if(upper - 1 > j  and abs(target - ans) > abs(target - (nums[i] + nums[j] + nums[upper - 1]))) {
                        ans = nums[i] + nums[j] + nums[upper - 1];
                    }
                }
                else {
                    if(upper - 1 > j and abs(target - ans) > abs(target - (nums[i] + nums[j] + nums[upper - 1]))) {
                        ans = nums[i] + nums[j] + nums[upper - 1];
                    }
                    if(upper > j and abs(target - ans) > abs(target - (nums[i] + nums[j] + nums[upper]))) {
                        ans = nums[i] + nums[j] + nums[upper];
                    }
                }
            }
        }
        return ans;
    }
};