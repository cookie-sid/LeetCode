class Solution {
public:
    void traverse(vector<vector<char>>& grid, int x, int y, vector<vector<bool>>& in_island) {
        if(x >= grid.size() or y >= grid[0].size() or x < 0 or y < 0) 
            return;
        if(in_island[x][y] == true) {
            return;
        }
        if(grid[x][y] == '0') {
            return;
        }
        if(in_island[x][y] == false and grid[x][y] == '1') {
            in_island[x][y] = true;
            if(x - 1 >= 0) {
                traverse(grid,x-1,y,in_island);
            }
            if(y - 1 >= 0) {
                traverse(grid,x,y-1,in_island);
            }
            if(x + 1 < grid.size()) {
                traverse(grid,x+1,y,in_island);
            }
            if(y + 1 < grid[0].size()) {
                traverse(grid,x,y+1,in_island);
            }
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        
        vector<vector<bool>> in_island(grid.size());
        
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[i].size(); j++) {
                in_island[i].push_back(false);
            }
        }
        
        int count = 0;
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[i].size(); j++) {
                if(in_island[i][j] == false and grid[i][j] == '1') {
                    count++;
                    traverse(grid,i,j,in_island);
                }
            }
        }
        return count;
        
    }
};