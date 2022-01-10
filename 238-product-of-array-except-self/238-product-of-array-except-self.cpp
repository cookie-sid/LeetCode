class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        int zeros = 0;
        int prod = 1, prod_without_zeros = 1;
        for(auto x : nums) {
            if(x == 0) {
                zeros++;
                prod *= x;
                continue;
            }
            prod *= x;
            prod_without_zeros *= x;
        }
        
        if(zeros == 1) {
            for(int i = 0; i < nums.size(); i++) {
                if(nums[i] == 0) {
                    nums[i] = prod_without_zeros;
                }
                else {
                    nums[i] = 0;
                }
            }
            return nums;
        }
        
        if(zeros > 1) {
            for(int i = 0; i < nums.size(); i++) {
                nums[i] = 0;
            }
            return nums;
        }
        
        for(int i = 0; i < nums.size(); i++) {
            nums[i] = prod/nums[i];
        }
        
        return nums;
        
    }
};