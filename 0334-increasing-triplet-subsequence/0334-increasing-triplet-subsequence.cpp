class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size();
        vector<int> minTillNow(n);
        int mini = nums[0];
        for(int i = 1; i < n; i++) {
            minTillNow[i] = mini;
            mini = min(mini,nums[i]);
        }
        int maxi = nums[n-1];
        for(int i = n - 2; i > 0; i--) {
            if(maxi > nums[i] and nums[i] > minTillNow[i]) {
                return true;
            }
            maxi = max(maxi,nums[i]);
        }
        return false;
    }
};