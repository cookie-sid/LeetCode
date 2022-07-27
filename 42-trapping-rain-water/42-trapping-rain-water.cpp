class Solution {
public:
    int trap(vector<int>& height) {
        
        
        int n = height.size();
        if(n == 1) {
            return 0;
        }
        vector<int> ltor(n), rtol(n);
        ltor[0] = height[0];
        for(int i = 1; i < n; i++) {
            ltor[i] = max(height[i],ltor[i-1]);
        }
        rtol[n-1] = height[n-1];
        for(int i = n - 2; i >= 0; i--) {
            rtol[i] = max(rtol[i+1],height[i]);
        }
        int water = 0;
        for(int i = 1; i < n - 1; i++) {
            water += max(0,min(ltor[i-1],rtol[i+1]) - height[i]);
        }
        return water;
    }
};