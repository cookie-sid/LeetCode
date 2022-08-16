class Solution {
public:
    
    int oddEvenJumps(vector<int>& arr) {
        int n = arr.size();
        map<int,int> m;
        set<int> s;
        vector<pair<bool,bool>> dp(n);
        dp[n-1].first = true;
        dp[n-1].second = true;
        m[arr[n-1]] = n;
        s.insert(arr[n-1]);
        for(int i = n - 2; i >= 0; i--) {
            auto it = s.lower_bound(arr[i]);
            if(it == s.end()) {
                dp[i].second = false;
            }
            else {
                dp[i].second = dp[m[(*it)] - 1].first;
            }
            if(it != s.end() and (*it) == arr[i]) {
                dp[i].first = dp[m[(*it)] - 1].second;
            }
            else {
                if(it != s.begin()) {
                    it--;
                    dp[i].first = dp[m[(*it)] - 1].second;
                }
            }
            s.insert(arr[i]);
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