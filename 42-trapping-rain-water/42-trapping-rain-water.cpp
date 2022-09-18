class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> l2r(n), r2l(n);
        int maxTillNow = height[0];
        for(int i = 1; i < n; i++) {
            l2r[i] = maxTillNow;
            maxTillNow = max(maxTillNow,height[i]);
        }
        maxTillNow = height[n-1];
        for(int i = n - 2; i > -1; i--) {
            r2l[i] = maxTillNow;
            maxTillNow = max(maxTillNow,height[i]);
        }
        int ans = 0;
        for(int i = 1; i < n - 1; i++) {
            ans += max(height[i],min(r2l[i],l2r[i])) - height[i];
            
        }
        return ans;
    }
};