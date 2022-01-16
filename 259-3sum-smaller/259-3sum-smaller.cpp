class Solution {
public:
    int threeSumSmaller(vector<int>& nums, int target) {
        if(nums.size() < 3) {
            return 0;
        }
        sort(nums.begin(),nums.end());
        
        int ans = 0;
        for(int i = 0; i < nums.size() - 2; i++) {
            int required = target - nums[i];
            int start = i + 1, end = nums.size() - 1;
            while(start < end) {
                if(nums[start] + nums[end] < required) {
                    ans += end - start;
                    start++;
                }
                else {
                    end--;
                }
            }
        }
        return ans;
        
    }
};