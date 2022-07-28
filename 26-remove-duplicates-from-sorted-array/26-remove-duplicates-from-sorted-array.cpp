class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int start = 0;
        for(int i = 0; i < nums.size(); i++) {
            while(i < nums.size() and nums[i] == nums[start]) {
                i++;
            }
            if(i < nums.size()) {
                nums[start + 1] = nums[i];
                start++;
                i--;
            }
        }
        return start+1;
        
    }
};