class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        int first = 0, prev = 0, count = 0;
        
        for(int i = 0; i < nums.size(); i++) {
            if(i == 0) {
                count++;
                first++;
                prev = nums[i];
            }
            else {
                if(nums[i] == prev) {
                    if(count == 2) {
                        continue;
                    }
                    else {
                        int temp = nums[i];
                        nums[i] = nums[first];
                        nums[first] = temp;
                        first++;
                        count++;
                    }
                }
                else {
                    prev = nums[i];
                    int temp = nums[i];
                    nums[i] = nums[first];
                    nums[first] = temp;
                    first++;
                    count = 1;
                }
            }
        }
        
        return first;
        
    }
};