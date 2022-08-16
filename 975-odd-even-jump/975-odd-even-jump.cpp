class Solution {
public:
    
    int oddEvenJumps(vector<int>& arr) {
        int n = arr.size();
        map<int,int> m;
        set<int> s;
        vector<vector<bool>> dp(n,vector<bool>(2));
        dp[n-1][0] = true;
        dp[n-1][1] = true;
        m[arr[n-1]] = n;
        s.insert(arr[n-1]);
        for(int i = n - 2; i >= 0; i--) {
            auto it = s.lower_bound(arr[i]);
            if(it == s.end()) {
                dp[i][1] = false;
            }
            else {
                dp[i][1] = dp[m[(*it)] - 1][0];
            }
            if(it != s.end() and (*it) == arr[i]) {
                dp[i][0] = dp[m[(*it)] - 1][1];
            }
            else {
                if(it != s.begin()) {
                    it--;
                    dp[i][0] = dp[m[(*it)] - 1][1];
                }
            }
            s.insert(arr[i]);
            m[arr[i]] = i + 1;
        }
        int ans = 0;
        for(auto x : dp) {
            // cout<<x[0]<<" "<<x[1]<<endl;
            ans += x[1];
        }
        return ans;
    }
};