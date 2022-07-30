class Solution {
public:
    
    int getWorst(vector<int> &arr) {
        int worst = 0, total = 0;
        for(int i = 0; i < arr.size(); i++) {
            total + arr[i] < 0 ? total += arr[i] : total = 0;
            worst = min(worst,total);
        }
        return worst;
    }
    
    int maximumsSplicedArray(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        vector<int> diff(n);
        int sum1 = 0, sum2 = 0;
        for(int i = 0; i < n; i++) {
            sum1 += nums1[i];
            sum2 += nums2[i];
            diff[i] = nums1[i] - nums2[i];
        }
        int ans = max(sum1,sum2);
        ans = max(ans,sum1 - getWorst(diff));
        for(int i = 0; i < n; i++) {
            diff[i] *= -1;
        }
        ans = max(ans,sum2 - getWorst(diff));
        return ans;
    }
};