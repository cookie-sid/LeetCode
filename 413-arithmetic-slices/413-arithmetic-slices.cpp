class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int ans = 0;
        for(int i = 2; i <nums.size(); i++) {
            int diff = nums[i] - nums[i-1];
            int currans = 0;
            if(nums[i-1] - nums[i-2] == diff) {
                currans++;
            }
            else {
                continue;
            }
            int counter = i - 2;
            while(counter > 0 and nums[counter] - nums[counter - 1] == diff) {
                currans++;
                counter--;
            }
            ans += currans;
        }
        return ans;
    }
};