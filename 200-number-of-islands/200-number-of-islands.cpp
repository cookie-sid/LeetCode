class Solution {
public:
    void helper(vector<vector<bool>> & taken, vector<vector<char>> & grid, int currx, int curry, int x, int y) {
        if(currx >= x or curry >= y or currx < 0 or curry < 0)
            return;
        
        if(grid[currx][curry] == '0' or taken[currx][curry] == true) {
            return;
        }
        
        taken[currx][curry] = true;
        
        helper(taken,grid,currx + 1,curry,x,y);
        helper(taken,grid,currx,curry + 1,x,y);
        helper(taken,grid,currx - 1,curry,x,y);
        helper(taken,grid,currx,curry - 1,x,y);

    }
    
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<bool>> taken(n, vector<bool> (m,false));
        
        int count = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(taken[i][j] == false and grid[i][j] == '1') {
                    helper(taken,grid,i,j,n,m);
                    count++;
                }
            }
        }
        return count;
    }
};