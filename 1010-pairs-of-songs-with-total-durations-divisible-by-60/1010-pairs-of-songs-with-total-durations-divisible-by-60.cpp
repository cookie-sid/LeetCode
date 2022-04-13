class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        vector<int> rems(60);
        for(auto x : time) {
            rems[x%60]++;
        }
        long long ans = 0;
        for(int i = 1; i <= 29; i++) {
            ans += rems[i] * rems[60 - i];
        }
        ans += ((long long)rems[0] * (rems[0] - 1)) / 2;
        ans += ((long long)rems[30] * (rems[30] - 1)) / 2;
        return ans;
    }
};