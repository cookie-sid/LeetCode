class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        if(intervals.size() == 0) {
            ans.push_back(newInterval);
            return ans;
        }
        int startIndex = intervals.size() - 1;
        bool fixlast = false, fixnext = false, endfix = false;
        for(int i = 0; i < intervals.size(); i++) {
            if((newInterval[0] >= intervals[i][0] and newInterval[0] <= intervals[i][1]) 
              or newInterval[0] < intervals[i][0]) {
                if(newInterval[0] < intervals[i][0]) {
                    fixnext = true;
                }
                else {
                    fixlast = true;
                }
                startIndex = i;
                break;
            }
        }
        for(int i = 0; i <= startIndex; i++) {
            ans.push_back(intervals[i]);
        }
        if(fixlast) {
            int temp = startIndex;
            while(temp < intervals.size() and newInterval[1] >= intervals[temp][0]) {
                temp++;
            }
            if(temp == intervals.size()) {
                ans[ans.size() - 1][1] = max(intervals[temp - 1][1],newInterval[1]);
            }
            else {
                ans[ans.size() - 1][1] = max(intervals[temp - 1][1],newInterval[1]);
            }
            for(int i = temp; i < intervals.size(); i++) {
                ans.push_back(intervals[i]);
            }
            return ans;
        }
        if(fixnext) {
            ans[ans.size() - 1][0] = newInterval[0];
            int temp = startIndex;
            while(temp < intervals.size() and newInterval[1] >= intervals[temp][0]) {
                temp++;
            }
            if(temp == intervals.size()) {
                ans[ans.size() - 1][1] = max(intervals[temp - 1][1],newInterval[1]);
            }
            else {
                if(temp == 0) {
                    ans[ans.size() - 1][1] = newInterval[1];
                }
                else {
                    ans[ans.size() - 1][1] = max(intervals[temp - 1][1],newInterval[1]);
                }
            }
            for(int i = temp; i < intervals.size(); i++) {
                ans.push_back(intervals[i]);
            }
            return ans;
        }
        ans.push_back(newInterval);
        return ans;
    }
};