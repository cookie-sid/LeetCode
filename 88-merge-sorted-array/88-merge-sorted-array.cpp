class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if(m == 0) {
            for(int i = 0; i < n; i++) {
                nums1[i] = nums2[i];
            }
            return;
        }
        if(n == 0) {
            return;
        }
        int lastA = m - 1, lastB = n - 1, last = m + n - 1;
        while(lastA >= 0 and lastB >= 0 and last >= 0) {
            if(nums1[lastA] > nums2[lastB]) {
                nums1[last] = nums1[lastA];
                lastA--;
                last--;
            }
            else {
                nums1[last] = nums2[lastB];
                last--;
                lastB--;
            }
        }
        while(lastA >= 0 and last >= 0) {
            nums1[last--] = nums1[lastA--];
        }
        while(lastB >= 0 and last >= 0) {
            nums1[last--] = nums2[lastB--];
        }
    }
};