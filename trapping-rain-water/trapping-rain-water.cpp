class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> maxfromleft(height.size()), maxfromright(height.size());
        int maxi = -1;
        for(int i = 0; i < height.size(); i++) {
            maxfromleft[i] = max(maxi,height[i]);
            maxi = max(maxi,height[i]);
        }
        maxi = -1;
        for(int i = height.size() - 1; i > -1; i--) {
            maxfromright[i] = max(maxi,height[i]);
            maxi = max(maxi,height[i]);
        }
        vector<int> res(height.size());
        for(int i = 0; i < height.size(); i++) {
            if(i == 0 or i == height.size() - 1) {
                res[i] = height[i];
            }
            else {
                if(maxfromleft[i-1] < height[i]) {
                    res[i] = height[i];
                    continue;
                }
                if(maxfromright[i+1] < height[i]) {
                    res[i] = height[i];
                    continue;
                }
                res[i] = min(maxfromleft[i-1],maxfromright[i+1]);
            }
        }
        int ans = 0;
        for(int i = 0; i < res.size(); i++)
        {
            ans += abs(height[i] - res[i]);
        }
        return ans;
    }
};