class Solution {
public:
    
    int dfs(vector<vector<int>> &grid, vector<vector<bool>> &taken, int x, int y, int m, int n) {
        if(x < 0 or x >= m  or y < 0 or y >= n)
            return 0;
        if(grid[x][y] == 0 or taken[x][y]) {
            return 0;
        }
        taken[x][y] = true;
        int ans = 0;
        ans = max(ans,grid[x][y] + dfs(grid,taken,x+1,y,m,n));
        ans = max(ans,grid[x][y] + dfs(grid,taken,x,y+1,m,n));
        ans = max(ans,grid[x][y] + dfs(grid,taken,x-1,y,m,n));
        ans = max(ans,grid[x][y] + dfs(grid,taken,x,y-1,m,n));
        
        taken[x][y] = false;
        return ans;
    }
    
    int getMaximumGold(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>> taken(m, vector<bool> (n));
        int ans = 0;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                ans = max(ans,dfs(grid,taken,i,j,m,n));
            }
        }
        return ans;
    }
};