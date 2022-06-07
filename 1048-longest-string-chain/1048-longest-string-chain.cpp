class Solution {
public:
    
    bool checker(string a, string b) {
        bool ans = true, incorrect = false;
        int j = 0;
        for(int i = 0; i < b.length(); i++) {
            if(incorrect and a[j] != b[i]) {
                return false;
            }
            if(a[j] != b[i]) {
                j++;
                i--;
                incorrect = true;
            }
            else {
                j++;
            }
        }
        return ans;
    }
    
    int getLongest(string s, map<int,vector<string>> &m, int len, map<string,int> &dp) {
        if(dp[s] >= 1) {
            return dp[s];
        }
        if(len == 1) {
            dp[s] = 1;
            return 1;
        }
        int ans = 1;
        for(auto x : m[len - 1]) {
            if(checker(s,x)) {
                ans = max(ans,1 + getLongest(x,m,len - 1,dp));
            }
        }
        dp[s] = ans;
        return ans;
    }
    
    int longestStrChain(vector<string>& words) {
        map<int,vector<string>> m;
        for(auto x : words) {
            m[x.length()].push_back(x);
        }
        map<string,int> dp;
        int ans = 1;
        for(auto x : words) {
            if(dp[x] == 0) {
                ans = max(ans,getLongest(x,m,x.length(),dp));
            }
            else {
                ans = max(ans,dp[x]);
            }
        }
        return ans;
    }
};