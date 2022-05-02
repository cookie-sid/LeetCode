class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int start = 0, end = nums.size() - 1;
        while(start < end) {
            if(nums[start]%2 == 1) {
                while(end > start and nums[end]%2 == 1) {
                    end--;
                }
                if(end == start) {
                    return nums;
                }
                else {
                    int temp = nums[start];
                    nums[start] = nums[end];
                    nums[end] = temp;
                    start++;
                }
            }
            else {
                start++;
            }
        }
        return nums;
    }
};