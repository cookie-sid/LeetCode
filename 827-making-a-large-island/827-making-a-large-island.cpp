class Solution {
public:
    
    void helper(vector<vector<int>> &grid, vector<vector<int>> &taken, int x, int y, int n, int val) {
        if(x < 0 or x >= n or y < 0 or y >= n) {
            return;
        }
        if(taken[x][y] != 0 or grid[x][y] == 0)
            return;
        taken[x][y] = val;
        helper(grid,taken,x + 1,y,n,val);
        helper(grid,taken,x,y + 1,n,val);
        helper(grid,taken,x - 1,y,n,val);
        helper(grid,taken,x,y - 1,n,val);
    }
    
    int largestIsland(vector<vector<int>>& grid) {
        
        int n = grid.size();
        vector<vector<int>> taken(n, vector<int> (n,0));
        int val = 1;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1 and taken[i][j] == 0) {
                    helper(grid,taken,i,j,n,val);
                    val++;
                }
            }
        } 
        unordered_map<int,int> m;
        m[0] = 0;
        int maxi = 0;
        for(auto x : taken) {
            for(auto y : x) {
                if(y == 0)
                    continue;
                m[y]++;
                maxi = max(maxi,m[y]);
            }
        }
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 0) {
                    set<int> s;
                    s.insert(taken[max(i - 1,0)][j]);
                    s.insert(taken[min(i + 1,n - 1)][j]);
                    s.insert(taken[i][min(j + 1, n - 1)]);
                    s.insert(taken[i][max(j - 1,0)]);
                    int sum = 0;
                    for(auto x : s) {
                        sum += m[x];
                    }
                    maxi = max(maxi,sum + 1);
                }
            }
        }
        return maxi;
    }
};