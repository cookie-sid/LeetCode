class Solution {
public:
    int smallestCommonElement(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        int maxStart = -1, minEnd = 1e9;
        for(int i = 0; i < n; i++) {
            maxStart = max(mat[i][0],maxStart);
            minEnd = min(mat[i][m-1],minEnd);
        }
        for(int j = 0; j < m and mat[0][j] <= minEnd; j++) {
            int ct = 1;
            for(int i = 1; i < n; i++) {
                int ind = lower_bound(mat[i].begin(),mat[i].end(),mat[0][j]) - mat[i].begin();
                if(ind >= m or ind < 0) {
                    break;
                }
                else {
                    if(mat[i][ind] != mat[0][j])
                        break;
                    else
                        ct += 1;
                }
            }
            if(ct == n) {
                return mat[0][j];
            }
        }
        return -1;
    }
};