class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<int> ans(m);
        for(int i = 0; i < m; i++) {
            int x = 0, y = i;
            while(x < n and y >= 0 and y < m) {
                if(grid[x][y] == 1) {
                    if(y + 1 >= m or grid[x][y+1] == -1) {
                        ans[i] = -1;
                        break;
                    }
                    else {
                        x += 1;
                        y += 1;
                    }
                }
                else {
                    if(y - 1 < 0 or grid[x][y-1] == 1) {
                        ans[i] = -1;
                        break;
                    }
                    else {
                        x += 1;
                        y -= 1;
                    }
                }
            }
            if(x == n) {
                ans[i] = y;
            }
        }
        return ans;
    }
};