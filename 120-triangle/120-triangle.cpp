class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        
        for(int i = 1; i < triangle.size(); i++) {
            triangle[i][0] += triangle[i-1][0];
            for(int j = 1; j < triangle[i].size() - 1; j++) {
                triangle[i][j] += min(triangle[i-1][j], triangle[i-1][j-1]);
            }
            triangle[i].back() += triangle[i-1].back();
        }
        
        int ans = 1e9;
        for(int i = 0; i < triangle.back().size(); i++) {
            ans = min(ans,triangle.back()[i]);
        }
        
        return ans;
    }
};