class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        
        int numofzeros = 0, lastzeroat = -1;
        int left = 0, right = 0;
        int maxi = -1;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == 0) {
                if(numofzeros == 0) {
                    lastzeroat = i;
                    numofzeros++;
                    right++;
                    maxi = max(maxi,right - left);
                }
                else {
                    maxi = max(maxi,right - left);
                    numofzeros = 1;
                    left = lastzeroat + 1;
                    right = i+1;
                    lastzeroat = i;
                    maxi = max(maxi,right - left);
                }
            }
            else {
                right++;
                maxi = max(maxi,right - left);
            }
            maxi = max(maxi,right - left);
        }
        return maxi;
        
    }
};