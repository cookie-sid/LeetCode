class Solution {
public:
    
    bool check(int x, int y, int m, int n) {
        return !(x < 0 or y < 0 or x >= m or y >= n);
    }
    
    bool canGoRight(vector<vector<int>> &heights, vector<vector<bool>> &taken, int x, int y, int m, int n) {
        if(y == n - 1 or x == m - 1) {
            return true;
        }
        bool ans = false;
        taken[x][y] = true;
        if(check(x+1,y,m,n) and !taken[x+1][y] and heights[x+1][y] <= heights[x][y]) {
            ans = ans or canGoRight(heights,taken,x+1,y,m,n);
        }
        if(check(x,y+1,m,n) and !taken[x][y+1] and heights[x][y+1] <= heights[x][y]) {
            ans = ans or canGoRight(heights,taken,x,y+1,m,n);
        }
        if(check(x,y-1,m,n) and !taken[x][y-1] and heights[x][y-1] <= heights[x][y]) {
            ans = ans or canGoRight(heights,taken,x,y-1,m,n);
        }
        if(check(x-1,y,m,n) and !taken[x-1][y] and heights[x-1][y] <= heights[x][y]) {
            ans = ans or canGoRight(heights,taken,x-1,y,m,n);
        }
        taken[x][y] = false;
        return ans;
    }
    
    bool canGoLeft(vector<vector<int>> &heights, vector<vector<bool>> &taken, int x, int y, int m, int n) {
        if(y == 0 or x == 0) {
            return true;
        }
        bool ans = false;
        taken[x][y] = true;
        if(check(x+1,y,m,n) and !taken[x+1][y] and heights[x+1][y] <= heights[x][y]) {
            ans = ans or canGoLeft(heights,taken,x+1,y,m,n);
        }
        if(check(x,y+1,m,n) and !taken[x][y+1] and heights[x][y+1] <= heights[x][y]) {
            ans = ans or canGoLeft(heights,taken,x,y+1,m,n);
        }
        if(check(x,y-1,m,n) and !taken[x][y-1] and heights[x][y-1] <= heights[x][y]) {
            ans = ans or canGoLeft(heights,taken,x,y-1,m,n);
        }
        if(check(x-1,y,m,n) and !taken[x-1][y] and heights[x-1][y] <= heights[x][y]) {
            ans = ans or canGoLeft(heights,taken,x-1,y,m,n);
        }
        taken[x][y] = false;
        return ans;
    }
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size(), n = heights[0].size();
        vector<vector<bool>> taken(m, vector<bool> (n));
        map<pair<int,int>,pair<int,int>> dp;
        vector<vector<int>> ans;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(canGoRight(heights,taken,i,j,m,n) and canGoLeft(heights,taken,i,j,m,n)) {
                    ans.push_back({i,j});
                }
            }
        }
        return ans;
    }
};