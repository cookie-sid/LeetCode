class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        
        int n = temperatures.size();
        vector<int> ans(n);
        map<int,int> m;
        ans[n-1] = 0;
        m[temperatures[n-1]] = n - 1;
        for(int i = n - 2; i >= 0; i--) {
            int diff = 1e9;
            for(auto x : m) {
                if(x.first > temperatures[i]) {
                    diff = min(diff,x.second - i);
                }
            }
            if(diff == 1e9) {
                ans[i] = 0;
            }
            else {
                ans[i] = diff;
            }
            m[temperatures[i]] = i;
        }
        return ans;
    }
};