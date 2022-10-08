class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int ans = nums[0] + nums[1] + nums[2];
        for(int i = 0; i < nums.size() - 2; i++) {
            int start = i + 1, end = nums.size() - 1;
            while(start < end) {
                int val = nums[start] + nums[end];
                if(abs(target-ans) > abs(target-val-nums[i])) {
                    ans = val + nums[i];
                }
                if(val > target-nums[i]) {
                    end--;
                }
                else {
                    start++;
                }
            }
        }
        return ans;
    }
};