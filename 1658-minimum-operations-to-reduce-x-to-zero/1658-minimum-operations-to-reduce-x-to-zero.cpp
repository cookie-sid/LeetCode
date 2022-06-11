class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        vector<int> fromLeft(n);
        fromLeft[0] = nums[0];
        for(int i = 1; i < n; i++) {
            fromLeft[i] += fromLeft[i-1] + nums[i]; 
        }
        for(int i = n - 2; i >= 0; i--) {
            nums[i] += nums[i + 1];
        }
        int start = n - 1;
        int ans = n;
        while(start >= 0 and nums[start] < x) {
            start--;
        }
        if(start == -1) {
            return -1;
        }
        if(nums[start] == x) {
            ans = n - start;
        }
        start = 0;
        while(start < n and fromLeft[start] < x) {
            start++;
        }
        if(start == n) {
            return -1;
        }
        if(fromLeft[start] == x) {
            ans = min(ans,start + 1);
        }
        int end = n - 1;
        for(int i = start - 1; i >= 0; i--) {
            while(end >= i and fromLeft[i] + nums[end] <= x) {
                end--;
            }
            if(fromLeft[i] + nums[end + 1] == x) {
                ans = min(i + 1 + n - 1 - end,ans);
            }
        }
        return ans == n ? nums[0] == x ? ans : -1 : ans;
    }
};