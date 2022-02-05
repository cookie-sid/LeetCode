class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int,pair<int,pair<int,int>>> m;
        int ans = -1;
        for(int i = 0; i < nums.size(); i++) {
            int x = nums[i];
            if(m[x].first == 0) {
                m[x].first++;
                m[x].second.first = i;
                m[x].second.second = i;
            }
            else {
                m[x].first++;
                m[x].second.second = i;
            }
            ans = max(ans,m[x].first);
        }
        int maxilen = 1e9;
        for(auto x : m) {
            if(x.second.first == ans) {
                maxilen = min(x.second.second.second - x.second.second.first + 1,maxilen);
            }
        }
        return maxilen;
    }
};