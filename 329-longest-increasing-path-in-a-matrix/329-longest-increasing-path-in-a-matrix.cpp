class Solution {
public:
    
    int recurr(vector<vector<int>> &matrix, int &maxlen, int x, int y, int &m, int &n, int currlen, vector<vector<int>> &ans) {
        if(x < 0 or x > m - 1 or y < 0  or y > n - 1) {
            return 0;
        }
        maxlen = max(maxlen, currlen);
        
        if(ans[x][y] != 0) {
            return ans[x][y];
        }
        
        int maxi = 0;
        if(!(x < 0 or x > m - 1 or y < 0  or y > n - 1) and
           !(x + 1 < 0 or x + 1 > m - 1) and matrix[x + 1][y] > matrix[x][y]) {
            maxi = max(maxi,1 + recurr(matrix,maxlen,x+1,y,m,n,currlen + 1,ans));
        }
        if(!(x < 0 or x > m - 1 or y < 0  or y > n - 1) and
           !(x - 1 < 0 or x - 1 > m - 1) and matrix[x - 1][y] > matrix[x][y]) {
            maxi = max(maxi,1 + recurr(matrix,maxlen,x-1,y,m,n,currlen + 1,ans));
        }
        if(!(x < 0 or x > m - 1 or y < 0  or y > n - 1) and
           !(y + 1 < 0 or y + 1 > n - 1) and matrix[x][y + 1] > matrix[x][y]) {
            maxi = max(maxi,1 + recurr(matrix,maxlen,x,y+1,m,n,currlen + 1,ans));
        }
        if(!(x < 0 or x > m - 1 or y < 0  or y > n - 1) and
           !(y - 1 < 0 or y - 1 > n - 1) and matrix[x][y - 1] > matrix[x][y]) {
            maxi = max(maxi, 1 + recurr(matrix,maxlen,x,y-1,m,n,currlen + 1,ans));
        }
        ans[x][y] = max(ans[x][y],maxi);
        return maxi;
    }
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int maxlen = 1;
        int temp = -1;
        vector<vector<int>> ans(m, vector<int> (n));
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                temp = max(temp,1 + recurr(matrix,maxlen,i,j,m,n,1,ans));
            }
        }
        
        
        return temp;
    }
};