class Solution {
public:
    
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        int n = grid.size(), m = grid[0].size();
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                if(grid[i][j] == 2) {
                    q.push(make_pair(i,j));
                }
            }
        }
        
        int curr_size = q.size(), popped_out = 0, turns = 0;
        while(!q.empty()) {
            pair<int,int> top_pair = q.front();
            int x = top_pair.first, y = top_pair.second;
            if(x + 1 <= n - 1 and x + 1 >= 0 and y >= 0 and y <= m - 1) {
                if(grid[x + 1][y] == 1) {
                    grid[x + 1][y] = 2;
                    q.push(make_pair(x + 1,y));
                }
            }
            if(x - 1 <= n - 1 and x - 1 >= 0 and y >= 0 and y <= m - 1) {
                if(grid[x - 1][y] == 1) {
                    grid[x - 1][y] = 2;
                    q.push(make_pair(x - 1,y));
                }
            }
            if(x <= n - 1 and x >= 0 and y + 1 >= 0 and y + 1 <= m - 1) {
                if(grid[x][y + 1] == 1) {
                    grid[x][y + 1] = 2;
                    q.push(make_pair(x,y + 1));
                }
            }
            if(x <= n - 1 and x >= 0 and y - 1 >= 0 and y - 1 <= m - 1) {
                if(grid[x][y - 1] == 1) {
                    grid[x][y - 1] = 2;
                    q.push(make_pair(x,y - 1));
                }
            }
            q.pop();
            popped_out++;
            if(popped_out == curr_size) {
                popped_out = 0;
                curr_size = q.size();
                turns++;
            }
        }
        for(auto x : grid) {
            for(auto y : x) {
                if(y == 1) {
                    return -1;
                }
            }
        }
        return turns == 0 ? 0 : turns - 1;
    }
};