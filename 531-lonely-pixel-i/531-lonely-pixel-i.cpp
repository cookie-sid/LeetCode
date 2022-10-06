class Solution {
public:
    int findLonelyPixel(vector<vector<char>>& picture) {
        int n = picture.size(), m = picture[0].size();
        vector<int> row(n), col(m);
        for (int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(picture[i][j] == 'B') {
                    row[i] += 1;
                    col[j] += 1;
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(picture[i][j] == 'B') {
                    if(row[i] == 1 and col[j] == 1) {
                        ans += 1;
                    }
                }
            }
        }
        return ans;
    }
};