class Solution {
public:
    
    static bool comp (vector<int> a, vector<int> b) {
        if(a[0] != b[0]) {
            return a[0] < b[0];
        }
        return a[1] < b[1];
    }
    
    int minMeetingRooms(vector<vector<int>>& intervals) {
        
        sort(intervals.begin(),intervals.end(),comp);
        vector<vector<int>> count;
        for(int i = 0; i < intervals.size(); i++) {
            if(i == 0){
                count.push_back({intervals[i][1]});
            }
            else {
                bool pushed = false;
                for(int k = 0; k < count.size(); k++) {
                    int temp = count[k].size() - 1;
                    if(count[k][temp] <= intervals[i][0]) {
                        count[k].push_back(intervals[i][1]);
                        pushed = true;
                        break;
                    }
                }
                if(!pushed) {
                    count.push_back({intervals[i][1]});
                }
            }
        }
        return count.size();
    }
};