class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        if(nums.size() == 1) {
            return 1;
        }
        vector<int> consecfromleft(nums.size()), consecfromright(nums.size());
        int count = 0;
        int maxi = -1;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == 1) {
                count++;
                maxi = max(maxi,count);
            }
            else {
                count = 0;
            }
            consecfromleft[i] = count;
        }
        count = 0;
        for(int i = nums.size() - 1; i >= 0; i--) {
            if(nums[i] == 1) {
                count++;
            }
            else {
                count = 0;
            }
            consecfromright[i] = count;
        }
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == 0) {
                if(i == 0) {
                    maxi = max(maxi,1 + consecfromright[i+1]);
                }
                else if(i == nums.size() - 1) {
                    maxi = max(maxi,1 + consecfromleft[i-1]);
                }
                else {
                    maxi = max(maxi,1 + consecfromleft[i-1] + consecfromright[i+1]);
                }
            }
        }
        return maxi;
    }
};