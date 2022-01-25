class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        sort(stations.begin(),stations.end());
        if(target <= startFuel) {
            return 0;
        }
        if(stations.size() == 0) {
            return -1;
        }
        if(startFuel < stations[0][0]) {
            return -1;
        }
        
        vector<int> dp(stations.size() + 1);
        set<int> picked;
        dp[0] = startFuel;
        int lastvalid = 0;
        for(int i = 1; i <= stations.size(); i++) {
            int start = 0;
            int index = -1, maxi_boost = -1;
            while(start < stations.size() and dp[i-1] >= stations[start][0]) {
                if(picked.count(start) == 1) {
                    start++;
                    continue;
                }
                if(maxi_boost < dp[i-1] + stations[start][1]) {
                    maxi_boost = dp[i-1] + stations[start][1];
                    index = start;
                }
                start++;
            }
            cout<<maxi_boost<<" "<<start<<" "<<index<<endl;
            if(index == -1) {
                return -1;
            }
            else {
                dp[i] = maxi_boost;
                if(maxi_boost >= target) {
                    return i;
                }
                picked.insert(index);
            }
        }
        return -1;
    }
};