class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        int maxi = -1;
        for(int i = 0; i < nums.size(); i++) {
            m[nums[i]]++;
            maxi = max(maxi,m[nums[i]]);
        }
        vector<vector<int>> count(maxi + 1);
        for(auto x : m) {
            count[x.second].push_back(x.first);
        }
        vector<int> ans;
        for(int i = maxi; i >= 0; i--) {
            if(count[i].size() <= k) {
                k -= count[i].size();
                for(auto x : count[i]) {
                    ans.push_back(x);
                }
            }
        }
        return ans;
    }
};