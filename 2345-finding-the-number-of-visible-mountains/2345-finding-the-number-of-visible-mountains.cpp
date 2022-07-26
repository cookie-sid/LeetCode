class Solution {
public:
    
    static bool cmp(vector<int> &v1, vector<int> &v2) {
        if(v1[0] - v1[1] != v2[0] - v2[1]) {
            return v1[0] - v1[1] < v2[0] - v2[1];
        }
        return v1[0] + v1[1] < v2[0] + v2[1];
    }
    
    int visibleMountains(vector<vector<int>>& peaks) {
        int ans = 0;
        map<int,int> m;
        sort(peaks.begin(),peaks.end(),cmp);
        int maxiTillNow = -1;
        for(int i = 0; i < peaks.size(); i++) {
            cout<<peaks[i][0]<<" "<<peaks[i][1]<<endl;
            int start = i;
            while(start + 1 < peaks.size() and peaks[start + 1][0] - peaks[start + 1][1] == peaks[i][0] - peaks[i][1]) {
                start++;
            }
            if(start == 0) {
                ans++;
                maxiTillNow = max(maxiTillNow,peaks[i][0] + peaks[i][1]);
            }
            else {
                if(peaks[start][0] + peaks[start][1] > maxiTillNow and peaks[start] != peaks[start-1]) {
                    ans++;
                    maxiTillNow = max(maxiTillNow,peaks[start][0] + peaks[start][1]);
                }
            }
            i = start;
        }
        return ans;
    }
};