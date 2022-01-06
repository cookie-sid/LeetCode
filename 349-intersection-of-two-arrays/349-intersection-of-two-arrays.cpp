class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> m;
        for(auto x : nums1) {
            m[x] = 1;
        }
        set<int> ans;
        for(auto x : nums2) {
            if(m[x] != 0) {
                ans.insert(x);
            }
        }
        vector<int> res;
        for(auto x : ans) {
            res.push_back(x);
        }
        return res;
    }
};