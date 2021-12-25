class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        if(n > m) {
            return findMedianSortedArrays(nums2,nums1);
        }
        
        int low = 0;
        int high = n;
        int combined = n + m;
        
        while(low <= high) {
            int mid1 = (low + high)/2;
            int mid2 = (combined + 1)/2 - mid1;
            
            int left_mid1 = mid1 - 1 > -1 ? nums1[mid1 - 1]:-1e9;
            int right_mid1 = mid1 < n ? nums1[mid1]:1e9;
            
            int left_mid2 = mid2 - 1 > -1 ? nums2[mid2 - 1]:-1e9;
            int right_mid2 = mid2 < m ? nums2[mid2]:1e9;
            
            if(left_mid1 <= right_mid2 and left_mid2 <= right_mid1) {
                if(combined % 2)
                    return (double) max(left_mid2,left_mid1);
                else
                    return ((double)max(left_mid2,left_mid1) + min(right_mid1,right_mid2))/2.0;
            }
            
            if(left_mid1 > right_mid2)
                high = mid1 - 1;
            else
                low = mid1 + 1;
        }
        return -1;
    }
};