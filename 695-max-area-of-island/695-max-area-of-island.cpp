class Solution {
public:
    
    int helper(vector<vector<bool>> &taken, vector<vector<int>> &grid, int cx, int cy, int x, int y) {
        if(cx < 0 or cx >= x or cy < 0 or cy >= y) {
            return 0;
        }
        
        if(taken[cx][cy] == true or grid[cx][cy] == 0) {
            return 0;
        }
        
        taken[cx][cy] = true;
        
        int ans = 0;
        if(cx + 1 < x and taken[cx + 1][cy] == false) {
            ans += grid[cx+1][cy];
            ans += helper(taken,grid,cx + 1,cy,x,y);
        }
        if(cy + 1 < y and taken[cx][cy + 1] == false) {
            ans += grid[cx][cy+1];
            ans += helper(taken,grid,cx,cy + 1,x,y);
        }
        if(cx - 1 >= 0 and taken[cx - 1][cy] == false) {
            ans += grid[cx-1][cy];
            ans += helper(taken,grid,cx - 1,cy,x,y);
        }
        if(cy - 1 >= 0 and taken[cx][cy - 1] == false) {
            ans += grid[cx][cy-1];
            ans += helper(taken,grid,cx,cy - 1,x,y);
        }
        
        return ans;
        
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        
        int n = grid.size(), m = grid[0].size();
        vector<vector<bool>> taken(n, vector<bool> (m,false));
        
        int maxi = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(taken[i][j] == false and grid[i][j] == 1) {
                    maxi = max(maxi,1 + helper(taken,grid,i,j,n,m));
                }
            }
        }
        return maxi ;
    }
};