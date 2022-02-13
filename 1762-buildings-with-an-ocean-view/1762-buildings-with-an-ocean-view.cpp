class Solution {
public:
    vector<int> findBuildings(vector<int>& heights) {
        
        vector<int> ans;
        int maxtillnow = -1;
        for(int i = heights.size() - 1; i >= 0; i--) {
            if(heights[i] > maxtillnow) {
                ans.push_back(i);
                maxtillnow = heights[i];
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};