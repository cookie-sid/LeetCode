class Solution {
public:
    int threeSumSmaller(vector<int>& nums, int target) {
        if(nums.size() < 3) {
            return 0;
        }
        
        sort(nums.begin(),nums.end());
        
        int ans = 0;
        for(int i = 0; i < nums.size() - 2; i++) {
            for(int j = i  + 1; j < nums.size() - 1; j++) {
                int required = target - nums[i] - nums[j];
                int upper = lower_bound(nums.begin() + j + 1,nums.end(),required) - nums.begin();
                if(upper - 1 > j) {
                    ans += upper - 1 - j;
                }
            }
        }
        return ans;
        
    }
};