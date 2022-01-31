class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int start = 0, ans = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == 0) {
                k--;
            }
            if(k < 0) {
                k += 1 - nums[start];
                start++;
            }
            if(k >= 0) {
                ans = max(ans,i - start + 1);
            }

        }
        return ans;
    }
};