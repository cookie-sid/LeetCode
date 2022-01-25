class Solution {
public:
    vector<int> findBuildings(vector<int>& heights) {
        int maxitillnow = -1;
        vector<int> ans;
        for(int i = heights.size() - 1; i >= 0; i--) {
            if(i == heights.size() - 1) {
                ans.push_back(i);
                maxitillnow = max(maxitillnow,heights[i]);
                continue;
            }
            if(heights[i] > maxitillnow) {
                ans.push_back(i);
                maxitillnow = heights[i];
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};