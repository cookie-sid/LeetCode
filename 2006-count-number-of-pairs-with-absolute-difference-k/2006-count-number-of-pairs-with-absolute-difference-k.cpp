class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        unordered_map<int,int> count;
        int ans = 0;
        for(auto x : nums) {
            if (x - k >= 0)
                ans += count[x - k];
            if (x + k <= 100)
                ans += count[x + k];
            
            count[x]++;
        }
        return ans;
    }
};