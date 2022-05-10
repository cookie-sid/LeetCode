class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        
        int firstNeg = -1, lastNeg = -1, lastZeroAt = -1;
        int ans = 0, currLen = 0, totalNegsInWindow = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] != 0) {
                currLen += 1;
            }
            else {
                firstNeg = -1, lastNeg = -1, lastZeroAt = i;
                currLen = 0;
                totalNegsInWindow = 0;
            }
            if(nums[i] < 0) {
                totalNegsInWindow += 1;
                if(firstNeg == -1) {
                    firstNeg = i;
                }
                lastNeg = i;
            }
            if(totalNegsInWindow%2 == 0) {
                ans = max(ans,currLen);
            }
            else {
                ans = max(ans,max(currLen - firstNeg + lastZeroAt,currLen - i + lastNeg - 1));
            }
            
        }
        return ans;
        
    }
};