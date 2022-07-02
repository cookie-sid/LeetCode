class Solution {
public:
    int minCostII(vector<vector<int>>& costs) {
        int k = costs[0].size();
        int ans = 1e9;
        vector<int> minFromLeft(k), minFromRight(k);
        minFromLeft[0] = costs[0][0];
        for(int i = 1; i < k; i++) {
            minFromLeft[i] = min(minFromLeft[i-1],costs[0][i]);
        }
        minFromRight[k-1] = costs[0][k-1];
        for(int i = k-2; i >= 0; i--) {
            minFromRight[i] = min(minFromRight[i+1],costs[0][i]);
        }
        
        for(int i = 1; i < costs.size(); i++) {
            for(int j = 0; j < k; j++) {
                if(j == 0) {
                    costs[i][j] += minFromRight[j+1];
                }
                else if(j == k - 1) {
                    costs[i][j] += minFromLeft[j-1];
                }
                else {
                    costs[i][j] += min(minFromLeft[j-1],minFromRight[j+1]);
                }
            }
            minFromLeft[0] = costs[i][0];
            for(int j = 1; j < k; j++) {
                minFromLeft[j] = min(minFromLeft[j-1],costs[i][j]);
            }
            minFromRight[k-1] = costs[i][k-1];
            for(int j = k-2; j >= 0; j--) {
                minFromRight[j] = min(minFromRight[j+1],costs[i][j]);
            }
        }
        for(int i = 0; i < k; i++) {
            ans = min(ans,costs.back()[i]);
        }
        return ans;
    }
};