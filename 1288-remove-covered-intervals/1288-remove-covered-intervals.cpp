class Solution {
public:
    
    static bool cmp(vector<int> &a, vector<int> &b) {
        if(a[0] != b[0]) {
            return a[0] < b[0];
        }
        return a[1] > b[1];
    }
    
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        
        sort(intervals.begin(),intervals.end(),cmp);
        
        int start, end, ans = 0;
        
        for(int i = 0; i < intervals.size(); i++) {
            if(i == 0) {
                start = intervals[i][0];
                end = intervals[i][1];
            }
            else {
                if(intervals[i][0] >= start and intervals[i][1] <= end) {
                    ans++;
                }
                else {
                    start = intervals[i][0];
                    end = intervals[i][1];
                }
            }
        }
        return (int)intervals.size() - ans;
        
    }
};