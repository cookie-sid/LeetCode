class Solution {
public:
    bool removeOnes(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<bool> ones(n);
        for(int i = 0; i < n; i++) {
            if(grid[0][i] == 1)
                ones[i] = true; 
        }
        for(int i = 1; i < m; i++) {
            int samepos = 0, diffpos = 0;
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1) {
                    if(ones[j])
                        samepos++;
                    else
                        diffpos++;
                }
                if(grid[i][j] == 0) {
                    if(ones[j])
                        diffpos++;
                    else
                        samepos++;
                }
            }
            if(!(samepos == 0 or diffpos == 0))
                return false;
        }
        return true;
    }
};