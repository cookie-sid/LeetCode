class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        map<int,int> m;
        int maxi = 0;
        for(auto x : nums) {
            m[x] = 1;
        }
        for(auto x : m) {
            m[x.first] = m[x.first - 1] + 1;
            maxi = max(maxi,m[x.first]);
        }
        return maxi;
    }
};