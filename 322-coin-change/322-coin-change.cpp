class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> knapsack(coins.size() + 1, vector<int> (amount + 1));
        int n = coins.size();
        
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= amount; j++) {
                knapsack[0][j] = 1e9;
                knapsack[i][j] = 1e9;
            }
        }
        
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= amount; j++) {
                if(j - coins[i-1] == 0) {
                    knapsack[i][j] = 1;
                }
                else if(j - coins[i-1] > 0) {
                    knapsack[i][j] = min(knapsack[i-1][j-coins[i-1]] + 1,
                                        min(knapsack[i-1][j], knapsack[i][j-coins[i-1]] + 1));
                }
                else {
                    knapsack[i][j] = knapsack[i-1][j];
                }
            }
        }
        
        knapsack[n][amount] == 1e9 ? knapsack[n][amount] = -1 : knapsack[n][amount] = knapsack[n][amount]; 
        return knapsack[n][amount];
    }
};