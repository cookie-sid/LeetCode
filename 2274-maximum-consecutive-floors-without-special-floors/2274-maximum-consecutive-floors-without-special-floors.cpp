class Solution {
public:
    int maxConsecutive(int bottom, int top, vector<int>& special) {
        sort(special.begin(),special.end());
        int ans = 0, prev = bottom, lastSat = -1;
        for(int i = 0; i < special.size() and special[i] <= top; i++) {
            if(special[i] >= prev) {
                ans = max(special[i] - prev,ans);
                prev = special[i] + 1;
            }
            lastSat = i;
        }
        ans = max(ans,top - special[lastSat]);
        return ans;
    }
};