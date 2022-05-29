class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        int m = points.size(), n = points[0].size();
        vector<vector<long long>> takeThis(m, vector<long long> (n));
        for(int i = 0; i < n; i++) {
            takeThis[0][i] = points[0][i];
        }
        vector<long long> left(n), right(n);
        for(int i = 1; i < m; i++) {
            left[0] = takeThis[i-1][0];
            for(int j = 1; j < n; j++) {
                left[j] = max(takeThis[i-1][j], left[j-1] - 1);
            }
            right[n-1] = takeThis[i-1][n-1];
            for(int j = n - 2; j > -1; j--) {
                right[j] = max(takeThis[i-1][j], right[j+1] - 1);
            }
            for(int j = 0; j < n; j++) {
                takeThis[i][j] = max(takeThis[i][j],points[i][j] + max(left[j],right[j]));
            }
        }
        long long ans = -1;
        for(int i = 0; i < n; i++) {
            ans = max(ans,takeThis[m-1][i]);
        }
        return ans;
    }
};