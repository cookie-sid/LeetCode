class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        sort(horizontalCuts.begin(),horizontalCuts.end());
        sort(verticalCuts.begin(),verticalCuts.end());
        int maxiH = -1, maxiV = -1, prev = 0;
        for(int i = 0; i < horizontalCuts.size(); i++) {
            maxiH = max(maxiH,horizontalCuts[i] -  prev);
            prev = horizontalCuts[i];
        }
        maxiH = max(maxiH,h - prev);
        prev = 0;
        for(int i = 0; i < verticalCuts.size(); i++) {
            maxiV = max(maxiV,verticalCuts[i] -  prev);
            prev = verticalCuts[i];
        }
        maxiV = max(maxiV,w - prev);
        int mod = 1e9 + 7;
        long long ans = (long long)maxiH * (long long) maxiV;
        ans %= mod;
        return (int) ans;
    }
};