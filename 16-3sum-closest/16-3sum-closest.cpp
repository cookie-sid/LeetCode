class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        
        sort(nums.begin(),nums.end());
        
        int ans = -1e9;
        for(int i = 0; i < nums.size() - 2; i++) {
            int required = target - nums[i];
            int start = i + 1, end = nums.size() - 1;
            while(start < end) {
                if(nums[start] + nums[end] < required) {
                    if(abs(target - ans) > abs(target - (nums[i] + nums[start] + nums[end]))) {
                        ans = nums[i] + nums[start] + nums[end];
                    }
                    start++;
                }
                else {
                    if(abs(target - ans) > abs(target - (nums[i] + nums[start] + nums[end]))) {
                        ans = nums[i] + nums[start] + nums[end];
                    }
                    end--;
                }
            }
        }
        return ans;
    }
};