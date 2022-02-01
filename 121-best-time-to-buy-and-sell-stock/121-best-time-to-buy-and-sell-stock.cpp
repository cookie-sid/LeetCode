class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mini = 1e9, maxi = -1, ans = 0;
        for(auto x : prices) {
            ans = max(0,max(x - mini,ans));
            mini = min(mini,x);
        }
        return ans;
    }
};