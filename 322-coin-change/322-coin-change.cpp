class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        sort(coins.begin(),coins.end());
        vector<int> ans(amount+1,1e9);
        ans[0] = 0;
        for(int i = 1; i <= amount; i++) {
            for(int j = 0; j < coins.size(); j++) {
                if(i >= coins[j]) {
                    ans[i] = min(ans[i],ans[i-coins[j]] + 1);
                }
            }
        }
        return ans[amount] == 1e9 ? -1 : ans[amount];
    }
};