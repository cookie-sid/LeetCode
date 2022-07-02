class Solution {
public:
    int minCostII(vector<vector<int>>& costs) {
        int k = costs[0].size();
        int ans = 1e9;
        for(int i = 1; i < costs.size(); i++) {
            for(int j = 0; j < k; j++) {
                int mini = 1e9;
                for(int l = 0; l < k; l++) {
                    if(l == j)
                        continue;
                    mini = min(costs[i-1][l],mini);
                }
                costs[i][j] += mini;
            }
        }
        for(int i = 0; i < k; i++) {
            ans = min(ans,costs.back()[i]);
        }
        return ans;
    }
};