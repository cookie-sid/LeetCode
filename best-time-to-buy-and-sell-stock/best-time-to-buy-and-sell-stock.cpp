class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxi = 0, minbuy = 1e9;
        for(int i = 1; i < prices.size(); i++) {
            minbuy = min(minbuy,prices[i-1]);
            maxi = max(maxi,prices[i] - minbuy);
        }
        return maxi;
    }
};