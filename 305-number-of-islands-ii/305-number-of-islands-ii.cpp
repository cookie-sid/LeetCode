class Solution {
public:
    
    bool isIt(int x, int y, int m, int n) {
        return x >= 0 and y >= 0 and x < m and y < n;
    }
    
    int get(map<int,int> &m, int x) {
        if(m[x] == x) {
            return x;
        }
        int tmp = get(m,m[x]);
        m[x] = tmp;
        return tmp;
    }
    
    vector<int> numIslands2(int m, int n, vector<vector<int>>& positions) {
        
        vector<vector<int>> grid(m, vector<int>(n));
        map<int,int> ids;
        for(int i = 0; i < 10001; i++) {
            ids[i] = i;
        }
        vector<vector<bool>> land(m, vector<bool>(n));
        vector<int> ans;
        int numOfIslands = 0, id = 1;
        
        for(int k = 0; k < positions.size(); k++) {
            int i = positions[k][0], j = positions[k][1];
            
            if(land[i][j]) {
                ans.push_back(numOfIslands);
                continue;
            }
            
            land[i][j] = true;
            grid[i][j] = id;
            set<int> s;
            if(isIt(i-1,j,m,n) and grid[i-1][j] != 0) {
                int actual = get(ids, grid[i-1][j]);
                s.insert(actual);
            }
            if(isIt(i+1,j,m,n) and grid[i+1][j] != 0) {
                int actual = get(ids, grid[i+1][j]);
                s.insert(actual);
            }
            if(isIt(i,j-1,m,n) and grid[i][j-1] != 0) {
                int actual = get(ids, grid[i][j-1]);
                s.insert(actual);
            }
            if(isIt(i,j+1,m,n) and grid[i][j+1] != 0) {
                int actual = get(ids, grid[i][j+1]);
                s.insert(actual);
            }
            int distinct = 0;
            for(auto x : s) {
                ids[x] = id;
                distinct += 1;
            }
            numOfIslands -= (distinct - 1);
            ans.push_back(numOfIslands);
            id++;
        }
        return ans;
    }
    /*
    1 1 1
    1 0 1
    0 1 0
    */
};