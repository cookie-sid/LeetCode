class Solution {
public:
    
    void recur(vector<vector<char>> &grid, vector<vector<bool>> &taken, int x, int y, int m, int n) {
        if(x < 0 or y < 0 or x >= m or y >= n) {
            return;
        }
        if(grid[x][y] != '1' or taken[x][y]) {
            return;
        }
        taken[x][y] = true;
        recur(grid,taken,x+1,y,m,n);
        recur(grid,taken,x-1,y,m,n);
        recur(grid,taken,x,y+1,m,n);
        recur(grid,taken,x,y-1,m,n);
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>> taken(m,vector<bool>(n));
        int ans = 0;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(!taken[i][j] and grid[i][j] == '1') {
                    ans += 1;
                    recur(grid,taken,i,j,m,n);
                }
            }
        }
        return ans;
    }
    
};