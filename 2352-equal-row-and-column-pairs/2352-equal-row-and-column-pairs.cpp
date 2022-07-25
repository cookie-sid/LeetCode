class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        map<string,int> r,c;
        int n = grid.size(), m = grid[0].size();
        for(int i = 0; i < n; i++) {
            string row = "";
            for(int j = 0; j < m; j++) {
                row += to_string(grid[i][j]);
                row += "_";
            }
            r[row]++;
        }
        
        for(int i = 0; i < m; i++) {
            string col = "";
            for(int j = 0; j < n; j++) {
                col += to_string(grid[j][i]);
                col += "_";
            }
            c[col]++;
        }
        
        int ans = 0;
        for(auto x : r) {
            ans += x.second * c[x.first];
        }
        return ans;
    }
};