class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int start = 0, freq = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(i == 0) {
                start++;
                freq++;
                continue;
            }
            else {
                if(nums[i] == nums[start - 1]) {
                    if(freq == 2) {
                        continue;
                    }
                    else {
                        freq++;
                        nums[start] = nums[i];
                        start++;
                        continue;
                    }
                }
                else {
                    freq = 1;
                    nums[start] = nums[i];
                    start++;
                    continue;
                }
            }
        }
        return start;
    }
};