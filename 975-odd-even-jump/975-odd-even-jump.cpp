class Solution {
public:
    
    int oddEvenJumps(vector<int>& arr) {
        int n = arr.size();
        map<int,int> m;
        vector<pair<bool,bool>> dp(n);
        dp[n-1].first = true;
        dp[n-1].second = true;
        m[arr[n-1]] = n;
        for(int i = n - 2; i >= 0; i--) {
            auto it = m.lower_bound(arr[i]);
            if(it == m.end()) {
                dp[i].second = false;
            }
            else {
                dp[i].second = dp[it -> second - 1].first;
            }
            if(it != m.end() and it -> first == arr[i]) {
                dp[i].first = dp[it -> second - 1].second;
            }
            else {
                if(it != m.begin()) {
                    it--;
                    dp[i].first = dp[it -> second - 1].second;
                }
            }
            m[arr[i]] = i + 1;
        }
        int ans = 0;
        for(auto x : dp) {
            // cout<<x[0]<<" "<<x[1]<<endl;
            ans += x.second;
        }
        return ans;
    }
};