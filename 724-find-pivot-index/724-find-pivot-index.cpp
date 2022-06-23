class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum = 0;
        for(auto x : nums) {
            sum += x;
        }
        int leftsum = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(leftsum == sum - nums[i]) {
                return i;
            }
            sum -= nums[i];
            leftsum += nums[i];
        }
        return -1;
    }
};