class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end());
        int ans = 1;
        int prevstart = points[0][0], prevend = points[0][1];
        for(int i = 1; i < points.size(); i++) {
            if(points[i][0] > prevend) {
                ans++;
                prevstart = points[i][0];
                prevend = points[i][1];
            }
            else {
                prevstart = points[i][0];
                prevend = min(points[i][1],prevend);
            }
        }
        return ans;
    }
};