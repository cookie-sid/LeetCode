class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int start = 0, count = 0, prod = 1;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] >= k) {
                start = i + 1;
                prod = 1;
                continue;
            }
            if(prod * nums[i] < k) {
                count += i - start + 1;
                prod *= nums[i];
                continue;
            }
            else {
                while(start < i and prod * nums[i] >= k) {
                    prod /= nums[start];
                    start++;
                }
                count +=  i - start + 1;
                if(prod * nums[i] < k) {
                    prod *= nums[i];
                }
            }
        }
        return count;
    }
};