class Solution {
public:
    bool canJump(vector<int>& nums) {
        
        if(nums.size() == 1)
            return true;
        int cango = nums[0];
        for(int i = 1; i < nums.size() and cango > 0; i++) {
            cango--;
            cango = max(cango, nums[i]);
            if(i + cango >= nums.size() - 1)
                return true;
        }
        return false;
    }
};