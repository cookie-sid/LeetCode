class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<int>> dp(n,vector<int> (m));
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(matrix[i][j] == '0') {
                    dp[i][j] = 0;
                }
                else {
                    if(j > 0) {
                        dp[i][j] = 1 + dp[i][j-1];
                    }
                    else {
                        dp[i][j] = 1;
                    }
                }
            }
        }
        
        int finalmax = -1;
        for(int i = 0; i < m; i++) {
            
            stack<int> s;
            s.push(-1);
            int ans = -1;
            for(int j = 0; j < n; j++) {
                while(s.top() != -1 and dp[s.top()][i] >= dp[j][i]) {
                    int curr = s.top();
                    s.pop();
                    ans = max(ans,dp[curr][i] * (j - s.top() - 1));
                }
                s.push(j);
            }
            int last = n - 1;
            while(s.top() != -1) {
                int curr = s.top();
                s.pop();
                ans = max(ans,dp[curr][i] * (last - s.top()));
            }
            finalmax = max(ans,finalmax);
        }
        
        return finalmax;
    }
};