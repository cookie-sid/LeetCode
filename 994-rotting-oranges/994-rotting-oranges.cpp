class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int turns = 0, n = grid.size(), m = grid[0].size();
        while(true) {
            bool any_change = false;
            vector<vector<int>> temp(n,vector<int>(m,0));
            for(int i = 0; i < grid.size(); i++) {
                for(int j = 0; j < grid[0].size(); j++) {
                    temp[i][j] = grid[i][j];
                }
            }
            for(int i = 0; i < grid.size(); i++) {
                for(int j = 0; j < grid[i].size(); j++) {
                    if(grid[i][j] == 2) {
                        if(grid[max(i-1,0)][j] == 1) {
                            temp[max(i-1,0)][j] = 2;
                            any_change = true;
                        }
                        if(grid[min(i+1,n - 1)][j] == 1) {
                            temp[min(i+1,n - 1)][j] = 2;
                            any_change = true;
                        }
                        if(grid[i][min(j + 1,m - 1)] == 1) {
                            temp[i][min(j + 1,m - 1)] = 2;
                            any_change = true;
                        }
                        if(grid[i][max(j-1,0)] == 1) {
                            temp[i][max(j-1,0)] = 2;
                            any_change = true;
                        }
                    }
                }
            }
            for(int i = 0; i < grid.size(); i++) {
                for(int j = 0; j < grid[0].size(); j++) {
                    grid[i][j] = temp[i][j];
                }
            }
            if(any_change){
                turns++;
            }
            else {
                break;
            }
        }
        for(auto x : grid) {
            for(auto y : x) {
                if(y == 1) {
                    return -1;
                }
            }
        }
        return turns;
    }
};