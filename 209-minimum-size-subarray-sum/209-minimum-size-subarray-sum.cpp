class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        
        int start = 0;
        int curr_sum = nums[0], ans = 1e9;
        if(curr_sum >= target) {
            return 1;
        }
        for(int i = 1; i < nums.size(); i++) {
            if(curr_sum + nums[i] < target) {
                curr_sum += nums[i];
            }
            else {
                while(start < i  and curr_sum + nums[i] >= target) {
                    curr_sum -= nums[start];
                    start++;
                }
                if(curr_sum + nums[i] >= target) {
                    ans = min(ans,i - start + 1);
                    curr_sum = 0;
                }
                else {
                    ans = min(ans,i - start + 2);
                    curr_sum += nums[i];
                }
            }
        }
        if(ans == 1e9) {
            ans = 0;
        }
        return ans;
    }
};