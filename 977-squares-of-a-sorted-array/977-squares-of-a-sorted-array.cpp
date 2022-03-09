class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int low = 0, high = nums.size() - 1;
        vector<int> ans(nums.size());
        int end = nums.size() - 1;
        while(low <= high) {
            int l_squared = nums[low]*nums[low];
            int h_squared = nums[high]*nums[high];
            if(h_squared > l_squared) {
                ans[end--] =  h_squared;
                high--;
            }
            else {
                ans[end--] = l_squared;
                low++;
            }
        }
        return ans;
    }
};