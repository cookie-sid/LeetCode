class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<int>> grid (n, vector<int> (m,0));
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                grid[i][j] = matrix[i][j] - '0';
                if(j > 0 and grid[i][j] != 0) {
                    grid[i][j] += grid[i][j-1];
                }
            }
        }
        
        int ans = -1;
        for(int j = 0; j < m; j++) {
            stack<int> s;
            s.push(-1);
            for(int i = 0; i < n; i++) {
                while(s.top() != -1 and grid[s.top()][j] >= grid[i][j]) {
                    int popped = s.top();
                    s.pop();
                    int mini = min(i - (s.top() + 1),grid[popped][j]);
                    ans = max(ans,mini*mini);
                }
                s.push(i);
            }
            while(s.top() != -1) {
                int popped = s.top();
                s.pop();
                int mini = min(n - (s.top() + 1), grid[popped][j]);
                ans = max(ans,mini * mini);
            }
        }
        
        return ans;
    }
};