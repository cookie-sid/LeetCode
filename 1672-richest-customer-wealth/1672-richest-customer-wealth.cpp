class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int maxi = -1;
        for(auto x : accounts) {
            int sum = 0;
            for(auto y : x) {
                sum += y;
            }
            maxi = max(maxi,sum);
        }
        return maxi;
    }
};