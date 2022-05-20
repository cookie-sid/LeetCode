class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> ans(m, vector<int> (n));
        
        ans[0][0] = 1 - obstacleGrid[0][0];
        
        for(int i = 1; i < m; i++) {
            if(obstacleGrid[i][0] == 1) 
                continue;
            ans[i][0] += ans[i-1][0]; 
        }
        
        for(int i = 1; i < n; i++) {
            if(obstacleGrid[0][i] == 1) 
                continue;
            ans[0][i] += ans[0][i-1];
        }
        
        for(int i = 1; i < m; i++) {
            for(int j = 1; j < n; j++) {
                if(obstacleGrid[i][j] == 1)
                    continue;
                ans[i][j] = ans[i-1][j] + ans[i][j-1];
            }
        }
        
        return ans[m-1][n-1];
    }
};