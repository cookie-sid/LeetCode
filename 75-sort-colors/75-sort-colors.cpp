class Solution {
public:
    void sortColors(vector<int>& nums) {
        
        int zeropointer = 0, twopointer = nums.size() - 1;
        
        for(int i = 0; i < nums.size() && i <= twopointer; i++) {
            
            while(nums[i] == 2 and i <= twopointer) {
                int temp = nums[twopointer];
                nums[twopointer] = nums[i];
                nums[i] = temp;
                twopointer--;
            }
            
            while(nums[i] == 0 and i >= zeropointer) {
                int temp = nums[zeropointer];
                nums[zeropointer] = nums[i];
                nums[i] = temp;
                zeropointer++;
            }
            
        }
        
        
    }
};