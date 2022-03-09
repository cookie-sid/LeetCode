class Solution {
public:
    
    void helper(vector<vector<int>> &grid, int x, int y, int n, int m, vector<vector<bool>> &taken, int counter) {
        
        if(x < 0 or x >= n or y < 0 or y >= m) {
            return;
        }
        
        if(grid[x][y] == 1 or taken[x][y])
            return;
        
        grid[x][y] = counter;
        taken[x][y] = true;
        helper(grid,x + 1,y,n,m,taken,counter);
        helper(grid,x,y + 1,n,m,taken,counter);
        helper(grid,x - 1,y,n,m,taken,counter);
        helper(grid,x,y - 1,n,m,taken,counter);
        
    }
    
    int closedIsland(vector<vector<int>>& grid) {

        int n = grid.size(), m = grid[0].size();
        int counter = 2, nums = 0;
        vector<vector<bool>> taken(n, vector<bool> (m, false));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 0 and taken[i][j] == false) {
                    helper(grid,i,j,n,m,taken,counter);
                    counter++;
                    nums++;
                }
            }
        }
        set<int> s;
        for(int i = 0; i < n; i++) {
            if(grid[i][0] != 1)
                s.insert(grid[i][0]);
            if(grid[i][m - 1] != 1)
                s.insert(grid[i][m - 1]);
        }
        for(int i = 0; i < m; i++) {
            if(grid[0][i] != 1)
                s.insert(grid[0][i]);
            if(grid[n - 1][i] != 1)
                s.insert(grid[n - 1][i]);
        }
        return nums - (int)s.size();
    }
    
};