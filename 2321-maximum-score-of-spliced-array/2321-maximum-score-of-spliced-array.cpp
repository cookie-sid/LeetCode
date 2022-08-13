class Solution {
public:
    
     int funct(vector<int> &nums1, vector<int> &nums2, int n) {
         vector<int> tmp(n);
         int total = 0;
         for(int i = 0; i < n; i++) {
             tmp[i] = nums1[i] - nums2[i];
             total += nums1[i];
         }
         int worst = 0, curr = 0;
         for(int i = 0; i < n; i++) {
             curr = min(tmp[i],curr + tmp[i]);
             worst = min(worst,curr);
         }
         if(worst > 0) {
             return total;
         }
         return total - worst;
     }
    
    int maximumsSplicedArray(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        return max(funct(nums1,nums2,n),funct(nums2,nums1,n));
    }
    
};