class Solution {
public:
    long long minimumMoney(vector<vector<int>>& transactions) {
        long long moneyLost = 0, maxVal = 0, q = 1e9 + 7;
        for(auto x : transactions) {
            moneyLost += max(0LL,(long long)x[0] - x[1]);
            if(x[0] <= x[1]) {
                maxVal = max(maxVal,(long long)x[0]);
            }
            else {
                maxVal = max(maxVal,(long long)x[1]);
            }
        }
        return moneyLost + maxVal;
    }
};