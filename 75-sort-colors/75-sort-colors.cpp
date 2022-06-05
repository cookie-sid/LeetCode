class Solution {
public:
    void sortColors(vector<int>& nums) {
        int first = 0, last = nums.size() - 1, ctr = 0;
        while(ctr <= last) {
            if(nums[ctr] == 0) {
                nums[first] = 0;
                first += 1;
            }
            if(nums[ctr] == 2) {
                while(last > ctr and nums[last] == 2) {
                    last -= 1;
                }
                if(nums[last] == 0) {
                    nums[first] = 0;
                    first += 1;
                }
                nums[last] = 2;
                last -= 1;
            }
            ctr += 1;
        }
        while(first <= last) {
            nums[first] = 1;
            first += 1;
        }
    }
};