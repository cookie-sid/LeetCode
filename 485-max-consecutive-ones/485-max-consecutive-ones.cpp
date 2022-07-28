class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ans = 0, count = 0;
        for(auto x : nums) {
            x == 1 ? count += 1 : count = 0;
            ans = max(ans,count);
        }
        return ans;
    }
};