class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long ans = 0;
        long long ct = 0;
        for(auto x: nums) {
            if(x == 0) {
                ct++;
            }
            else {
                ans += ((ct) * (ct + 1))/2;
                ct = 0;
            }
        }
        ans += ((ct) * (ct + 1))/2;
        return ans;
    }
};