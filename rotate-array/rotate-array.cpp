class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        
        
        k = k % nums.size();
        
        if(nums.size() == 1 or k == 0)
            return;
        
        int temp = nums[0], next = k, start = 0;
        int count = 0;
        while(true) {
            count++;
            int temp2 = nums[next];
            nums[next] = temp;
            temp = temp2;
            next = (next + k)%nums.size();
            if(next == (start + k)%nums.size()) {
                start++;
                next = (start + k)%nums.size();
                temp = nums[start];
            }
            if(count == nums.size()) {
                break;
            }

        }
        
    }
};