class Solution {
public:
    
    int dfs(vector<vector<int>> &grid, int x, int y, int r, int c, int id) {
        if(x < 0 or x >= r or y < 0 or y >= c) {
            return 0;
        }
        if(grid[x][y] == 0 or grid[x][y] != 1) {
            return 0;
        }
        grid[x][y] = id;
        int ans = 1;
        ans += dfs(grid,x + 1,y,r,c,id);
        ans += dfs(grid,x,y + 1,r,c,id);
        ans += dfs(grid,x - 1,y,r,c,id);
        ans += dfs(grid,x,y - 1,r,c,id);
        return ans;
    }
    
    
    
    int largestIsland(vector<vector<int>>& grid) {
        int r = grid.size(), c = grid[0].size();
        map<int,int> m;
        int id = 2, ans = 0;
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                if(grid[i][j] == 1) {
                    m[id] = dfs(grid,i,j,r,c,id);
                    ans = max(ans,m[id]);
                    id += 1;
                }
            }
        }
        
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                if(grid[i][j] == 0) {
                    set<int> s;
                    if(i > 0 and grid[i-1][j] != 0) {
                        s.insert(grid[i-1][j]);
                    }
                    if(j > 0 and grid[i][j-1] != 0) {
                        s.insert(grid[i][j-1]);
                    }
                    if(i < r - 1 and grid[i+1][j] != 0) {
                        s.insert(grid[i+1][j]);
                    }
                    if(j < c - 1 and grid[i][j+1] != 0) {
                        s.insert(grid[i][j+1]);
                    }
                    int sum = 0;
                    for(auto x : s) {
                        sum += m[x];
                    }
                    ans = max(ans,sum + 1);
                }
            }
        }
        return ans;
    }
};