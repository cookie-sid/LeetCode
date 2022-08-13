class Solution {
public:
    
    void allS(vector<vector<int>> &v, vector<int> &nums, int curr, int selected, int n, int total) {
        if(curr == n) {
            v[selected].push_back(total);
            return;
        }
        allS(v,nums,curr+1,selected+1,n,total+nums[curr]);
        allS(v,nums,curr+1,selected,n,total);
    }
    
    int minimumDifference(vector<int>& nums) {
        int n = nums.size();
        n = n/2;
        int total = 0;
        for(auto x : nums) {
            total += x;
        }
        vector<vector<int>> vR(n+1);
        allS(vR,nums,0,0,n,0);
        vector<vector<int>> vL(n+1);
        allS(vL,nums,n,0,2*n,0);
        int req = total/2;
        int minDiff = 1e9;
        for(int i = 0; i < vL.size(); i++) {
            sort(vL[i].begin(),vL[i].end());
        }
        for(int i = 0; i < vR.size(); i++) {
            sort(vR[i].begin(),vR[i].end());
        }
        for(int i = 0; i <= n; i++) {
            for(int j = 0; j < vL[i].size(); j++) {
                int first = vL[i][j];
                int second = req - first;
                int ind = lower_bound(vR[n-i].begin(),vR[n-i].end(),second) - vR[n-i].begin();
                if(ind - 1 >= 0) {
                    minDiff = min(minDiff,abs(total - 2 * (vL[i][j] + vR[n-i][ind-1])));
                }
                if(ind + 1 < vR[n-i].size()) {
                    minDiff = min(minDiff,abs(total - 2 * (vL[i][j] + vR[n-i][ind+1])));
                }
                if(ind >= 0 and ind < vR[n-i].size()) {
                    minDiff = min(minDiff,abs(total - 2 * (vL[i][j] + vR[n-i][ind])));
                }
            }
        }
        return minDiff;
    }
};