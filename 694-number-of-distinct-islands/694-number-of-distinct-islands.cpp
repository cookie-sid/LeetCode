class Solution {
public:
    
    void recur(vector<vector<int>> &grid, vector<vector<bool>> &vis, 
               int x, int y, int m, int n, vector<pair<int,int>> &mems) {
        if(x < 0 or x > m - 1 or y < 0 or  y > n - 1) 
            return;
        if(vis[x][y] or grid[x][y] == 0)
            return;
        
        vis[x][y] = true;
        mems.push_back(make_pair(x,y));
        recur(grid,vis,x+1,y,m,n,mems);
        recur(grid,vis,x,y+1,m,n,mems);
        recur(grid,vis,x-1,y,m,n,mems);
        recur(grid,vis,x,y-1,m,n,mems);
    }
    
    int numDistinctIslands(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> vis(m, vector<bool> (n));
        map<int,vector<vector<pair<int,int>>>> mp;
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                
                if(vis[i][j] or grid[i][j] == 0)
                    continue;
                
                vector<pair<int,int>> mems;
                recur(grid,vis,i,j,m,n,mems);
                bool sameIslandPresent = false;
                
                for(auto x : mp[mems.size()]) {
                    
                    bool allDiffSame = true;
                    
                    for(int i = 1; i < x.size(); i++) {
                        
                        if(!(mems[i].first - mems[i-1].first == x[i].first - x[i-1].first 
                           and mems[i].second - mems[i-1].second == x[i].second - x[i-1].second)) {
                            allDiffSame = false;
                            break;
                        }
                    }
                    
                    if(allDiffSame) {
                        sameIslandPresent = true;
                        break;
                    }
                }
                if(!sameIslandPresent) {
                    mp[mems.size()].push_back(mems);
                }
            }
        }
        int total = 0;
        for(auto x : mp) {
            // cout<<x.first<<endl;
            total += x.second.size();
            // cout<<x.second.size()<<"gg";
            // for(auto y : x.second) {
            //     for(auto z : y) {
            //         cout<<z.first<<" "<<z.second<<"  ";
            //     }
            //     cout<<endl;
            // }
        }
        return total;
    }
};