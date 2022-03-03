class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        
        int prevdiff = -1e9, countsince = 0, ans = 0;
        for(int i = 1; i < nums.size(); i++) {
            if(prevdiff == -1e9) {
                prevdiff = nums[i] - nums[i-1];
                countsince++;
                continue;
            }
            if(nums[i] - nums[i-1] == prevdiff) {
                countsince++;
            }
            else {
                ans += (countsince + 2) * (countsince - 1) - (countsince + 1)*(countsince + 2)/2 + 3;
                countsince = 1;
                prevdiff = nums[i] - nums[i-1];
            }
        }
        if(countsince > 0)
            ans += (countsince + 2) * (countsince - 1) - (countsince + 1)*(countsince + 2)/2 + 3;
        return ans;
    }
};