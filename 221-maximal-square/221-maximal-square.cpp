class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<int>> grid(n,vector<int> (m,0));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                grid[i][j] = matrix[i][j] - '0';
            }
        }
        for(int i = 0; i < n; i++) {
            for(int j = 1; j < m; j++) {
                if(grid[i][j] == 0) {
                    continue;
                }
                grid[i][j] += grid[i][j-1];
            }
        }
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                cout<<grid[i][j]<<" ";
            }
            cout<<endl;
        }
        
        int maxi = -1;
        for(int i = 0; i < m; i++) {
            stack<int> s;
            s.push(-1);
            for(int j = 0; j < n; j++) {
                while(s.top() != -1 and grid[s.top()][i] >= grid[j][i]) {
                    int up = s.top();
                    s.pop();
                    if(j - s.top() - 1 >= grid[up][i]) {
                        maxi = max(maxi,grid[up][i]*grid[up][i]);
                    }
                }
                if(j - s.top() >= grid[j][i]) {
                    maxi = max(maxi,grid[j][i] * grid[j][i]);
                }
                s.push(j);
            }
            int last = n - 1;
            while(s.top() != -1) {
                int up = s.top();
                s.pop();
                if(last - s.top() >= grid[up][i]) {
                    maxi = max(maxi,grid[up][i]*grid[up][i]);
                }
                last = up;
            }
        }
        return maxi;
    }
};