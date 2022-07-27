class Solution {
public:
    int trap(vector<int>& height) {
        
        
        int n = height.size();
        if(n == 1) {
            return 0;
        }
        vector<int> rtol(n);
        rtol[n-1] = height[n-1];
        for(int i = n - 2; i >= 0; i--) {
            rtol[i] = max(rtol[i+1],height[i]);
        }
        int water = 0, maxi = height[0];
        for(int i = 1; i < n - 1; i++) {
            water += max(0,min(maxi,rtol[i+1]) - height[i]);
            maxi = max(maxi,height[i]);
        }
        return water;
    }
};