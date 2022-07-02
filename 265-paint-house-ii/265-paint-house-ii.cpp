class Solution {
public:
    int minCostII(vector<vector<int>>& costs) {
        int k = costs[0].size();
        int ans = 1e9;
        
        for(int i = 1; i < costs.size(); i++) {
            
            int minIndex = -1, secondMinIndex = -1;
            for(int j = 0; j < k; j++) {
                if(minIndex == -1 and secondMinIndex == -1) {
                    minIndex = j;
                }
                else if(secondMinIndex == -1) {
                    if(costs[i-1][minIndex] > costs[i-1][j]) {
                        secondMinIndex = minIndex;
                        minIndex = j;
                    }
                    else {
                        secondMinIndex = j;
                    }
                }
                else {
                    if(costs[i-1][minIndex] >= costs[i-1][j]) {
                        secondMinIndex = minIndex;
                        minIndex = j;
                    }
                    else if(costs[i-1][minIndex] < costs[i-1][j] and costs[i-1][secondMinIndex] > costs[i-1][j]) {
                        secondMinIndex = j;
                    }
                }
            }
            
            for(int j = 0; j < k; j++) {
                if(j == minIndex) {
                    costs[i][j] += costs[i-1][secondMinIndex];
                }
                else {
                    costs[i][j] += costs[i-1][minIndex];
                }
            }
        }
        for(int i = 0; i < k; i++) {
            ans = min(ans,costs.back()[i]);
        }
        return ans;
    }
};